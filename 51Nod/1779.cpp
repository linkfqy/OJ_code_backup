#include<cstdio>
#include<cstring>
#include<algorithm>
#define lowbit(x) ((x)&-(x))
using namespace std;
typedef long long ll;
inline char nc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int red(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=(res<<3)+(res<<1)+ch-48,ch=nc();
	return res*f;
}

const int maxs=1050000;
int n,m,f[maxs];
inline int num1(int x){
	int res=0;
	while (x) res++,x^=lowbit(x);
	return res;
}
int main(){
	n=red(),m=red();
	memset(f,192,sizeof(f));
	f[0]=0;
	while (m--){
		int x=red()-1;
		for (int s=0;s<(1<<n);s++)
		 if (!(s&(1<<x))){
			f[s|(1<<x)]=max(f[s|(1<<x)],f[s]+num1(s>>x));
		 }
	}
	printf("%d",f[(1<<n)-1]);
	return 0;
} 
