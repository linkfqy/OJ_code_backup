#include<cstdio>
#include<algorithm>
#define mp make_pair
#define X first
#define Y second
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
int n,m,f[maxn];
pair<int,int> a[maxn];
int tot,lnk[maxn],nxt[maxn],son[maxn],w[maxn];
inline void add(int x,int y,int z){
	z=min(z,x-y);
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=z;
}
int main(){
	n=red();
	for (int i=1,x,y;i<=n;i++){
		x=red(),y=red();
		if (x+y+1<=n) a[++m]=mp(x+1,n-y);
	}
	sort(a+1,a+1+m);
	{
		int x=1;
		for (int i=2;i<=m;i++)
		 if (a[i]==a[i-1]) x++;else add(a[i-1].Y,a[i-1].X-1,x),x=1;
		add(a[m].Y,a[m].X-1,x);
	}
	f[0]=0;
	for (int i=1;i<=n;i++){
		f[i]=f[i-1];
		for (int j=lnk[i];j;j=nxt[j])
		 f[i]=max(f[i],f[son[j]]+w[j]);
	}
	printf("%d",n-f[n]);
	return 0;
}
