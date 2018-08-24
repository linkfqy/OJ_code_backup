#include<cstdio>
#include<cstring>
#define cl(x,y) memset(x,y,sizeof(x))
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

const int maxn=1000005;
int t,num[maxn],cnt[maxn],x,y,n,m,a,b;
inline int Abs(int x) {return x>0?x:-x;}
int main(){
	t=red();
	for (int i=1;i<=t;i++) num[red()]++;
	if (num[0]!=1) return puts("-1"),0;
	for (int i=1;i<=1e6;i++) if (num[i]) b=i;
	for (int i=1;i<=1e6;i++)
	 if (num[i]!=4*i) {x=i;break;}
	for (n=1;n<=t;n++) if (t%n==0){
		m=t/n; y=n+m-x-b;
		cl(cnt,0);
		for (int i=1;i<=n;i++)
		 for (int j=1;j<=m;j++)
		  cnt[Abs(i-x)+Abs(j-y)]++;
		bool suc=1;
		for (int i=0;i<=n+m;i++) if (cnt[i]!=num[i]) suc=0;
		if (suc) return printf("%d %d\n%d %d",n,m,x,y),0;
	}
	return puts("-1"),0;
}
