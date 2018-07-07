#include<cstdio>
#include<cstring>
#define abs(x) ((x)>0?(x):-(x))
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

const int maxn=200005;
int tst,n,m,x[maxn],y[maxn];
bool vis[maxn];
bool check(){
	for (int i=1;i<=n;i++)
	 for (int j=i+1;j<=n;j++)
	  if (vis[abs(x[i]-x[j])+abs(y[i]-y[j])]) return 1;
	   else vis[abs(x[i]-x[j])+abs(y[i]-y[j])]=1;
	return 0;
}
int main(){
	tst=red();
	while (tst--){
		n=red(),m=red();
		for (int i=1;i<=n;i++) x[i]=red(),y[i]=red();
		memset(vis,0,sizeof(vis));
		printf(check()?"YES\n":"NO\n");
	}
	return 0;
}
