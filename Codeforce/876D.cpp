#include<cstdio>
#include<algorithm>
#define lowbit(x) ((x)&-(x))
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

const int maxn=300005;
int n,a[maxn],BIT[maxn];
bool vis[maxn];
void ist(int x,int w){
	for (int i=x;i<=n;i+=lowbit(i)) BIT[i]+=w;
}
int qry(int x){
	int res=0;
	for (int i=x;i;i-=lowbit(i)) res+=BIT[i];
	return res;
}
int main(){
	n=red();printf("1 ");
	for (int i=1,max0=n;i<=n;i++){
		int x=red();
		vis[x]=1;ist(x,1);
		while (vis[max0]) max0--;
		printf("%d ",qry(max0)+1);
	}
	return 0;
}