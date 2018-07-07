#include<cstdio>
#include<algorithm>
using namespace std;
inline char nc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int red(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
	return res*f;
}

const int maxn=100005;
int n,L,T,a[maxn],num;
int main(){
	n=red(),L=red(),T=red();
	for (int i=0;i<n;i++){
		int x=red(),f=red();
		if (f==1){
			(num+=(x+T)/L)%=n;
			a[i]=(x+T)%L;
		}else{
			(num-=(L-x-1+T)/L)%=n;
			a[i]=((x-T)%L+L)%L;
		}
	}
	sort(a,a+n);
	for (int i=0;i<n;i++) printf("%d\n",a[(i+num+n)%n]);
	return 0;
}
