#include<cstdio>
#include<algorithm>
using namespace std;
inline char nc(){
	static char buf[100000],*l=buf,*r=buf;
	return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++;
}
inline int red(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
	return res*f;
}

const int maxn=2000005,MOD=19260817;
int tst,n,fa[MOD],x[maxn],y[maxn],c[maxn];
inline int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int main(){
	tst=red();
	while (tst--){
		int suc=1; n=red();
		for (int i=1;i<=n;i++) x[i]=red(),y[i]=red(),c[i]=red();
		for (int i=1;i<MOD;i++) fa[i]=i;
		for (int i=1;i<=n;i++)
		 if (c[i]) fa[getfa(x[i]%MOD)]=getfa(y[i]%MOD);
		for (int i=1;i<=n;i++)
		 if (!c[i]&&getfa(x[i]%MOD)==getfa(y[i]%MOD))  {suc=0;break;}
		puts(suc?"YES":"NO");
	}
	return 0;
}
