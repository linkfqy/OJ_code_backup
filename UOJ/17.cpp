#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
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

const int maxn=10005,maxm=1005,INF=0x3f3f3f3f;
int n,m,q,up[maxn],down[maxn],f[maxn][maxm],pos[maxn];
bool vis[maxn][maxm];
int main(){
	n=red(),m=red(),q=red();
	for (int i=0;i<n;i++) up[i]=red(),down[i]=red();
	for (int i=1;i<=q;i++){
		int x=red(),l=red(),h=red();pos[i]=x;
		for (int j=1;j<=l;j++) vis[x][j]=1;
		for (int j=h;j<=m;j++) vis[x][j]=1;
	}
	cl(f,63);
	for (int i=1;i<=m;i++) f[0][i]=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (j>up[i-1]) f[i][j]=min(f[i-1][j-up[i-1]],f[i][j-up[i-1]])+1;
		}
		for (int j=m-up[i-1];j<=m;j++)
		 f[i][m]=min(f[i][m],min(f[i-1][j],f[i][j])+1);
		for (int j=1;j<=m;j++){
			if (j+down[i-1]<=m) f[i][j]=min(f[i][j],f[i-1][j+down[i-1]]);
		}
		for (int j=1;j<=m;j++) if (vis[i][j]) f[i][j]=INF;
	}
	int ans=INF,cnt=q;
	for (int j=1;j<=m;j++) ans=min(ans,f[n][j]);
	if (ans<INF) return printf("1\n%d",ans),0;
	for (int i=n-1;i;i--){
		bool suc=0;
		for (int j=1;j<=m;j++)
		 if (f[i][j]<INF) {suc=1;break;}
		if (suc) break;
		if (vis[i][m]) cnt--;
	}
	printf("0\n%d",cnt);
	return 0;
}
