#include<cstdio>
#include<cstring>
#define cl(x,y) memset(x,y,sizeof(x))
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

const int maxs=200005,maxn=105;
int tst,n,s,t[maxn];
double p[maxn],f[maxs];
int main(){
	tst=red();
	while (tst--){
		n=red(),s=red();
		for (int i=1;i<=n;i++)
		 t[i]=red(),p[i]=red()/100.0;
		cl(f,0);
		f[0]=1;double ans=0;
		for (int i=0;i<s;i++)
		 for (int j=1;j<=n;j++)
		  f[i+t[j]]+=f[i]*p[j];
		for (int i=s+1;i<=200000;i++)
		 ans+=(i-s)*f[i];
		printf("%.4lf\n",ans);
	}
	return 0;
}
