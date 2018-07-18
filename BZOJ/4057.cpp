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

const int maxn=25,maxs=(1<<20)+5;
int tst,n,d[maxn][maxn],a[maxn],mon[maxn];
bool f[maxs];
int main(){
	tst=red();
	while (tst--){
		n=red();
		for (int i=0;i<n;i++)
		 for (int j=0;j<n;j++) d[i][j]=red();
		cl(f,0); f[(1<<n)-1]=1;
		for (int s=(1<<n)-1;s;s--){
			a[0]=0;
			for (int i=0;i<n;i++) if (s&(1<<i)) a[++a[0]]=i,mon[i]=0;
			for (int i=1;i<=a[0];i++)
			 for (int j=1;j<=a[0];j++)
			  mon[a[i]]-=d[a[i]][a[j]];
			for (int i=1;i<=a[0];i++)
			 if (mon[a[i]]<0) f[s^(1<<a[i])]|=f[s];
		}
		bool fir=1;
		for (int i=0;i<n;i++) if (f[1<<i]) if (fir) printf("%d",i+1),fir=0;else printf(" %d",i+1);
		if (fir) printf("0");
		if (tst) putchar('\n');
	}
	return 0;
}
