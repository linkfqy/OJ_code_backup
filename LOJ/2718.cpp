#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
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

const int maxn=400005,maxe=1200005;
int tst,n,e,q,N,K,S;
int tot,lnk[2][maxn],nxt[maxe],son[maxe],w[maxe];
inline void add(int x,int y,int z,int id){
	son[++tot]=y;nxt[tot]=lnk[id][x];lnk[id][x]=tot;w[tot]=z;
}
struct edge{
	int x,y,w,h;
	bool operator<(const edge&b)const {return h>b.h;}
}a[maxe];
int dst[maxn];
bool vis[maxn];
struct data{
	int x,d;
	data () {}
	data (int _x,int _d):x(_x),d(_d) {}
	bool operator<(const data&b)const {return d>b.d;}
};
priority_queue<data> H;
void DIJ(){
	while (!H.empty()) H.pop();
	cl(dst,0x7f);cl(vis,0);
	dst[1]=0;H.push(data(1,0));
	while (!H.empty()){
		data k=H.top();H.pop(); if (vis[k.x]) continue;
		vis[k.x]=1;
		for (int j=lnk[0][k.x];j;j=nxt[j])
		 if (!vis[son[j]]&&dst[son[j]]>dst[k.x]+w[j])
		  dst[son[j]]=dst[k.x]+w[j],H.push(data(son[j],dst[son[j]]));
	}
}
int fa[maxn],f[maxn][20],val[maxn],MIN[maxn];
inline int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
void kruskal(){
	sort(a+1,a+1+e); N=n; cl(val,0);
	for (int i=1;i<=(n<<1);i++) fa[i]=i;
	for (int i=1;i<=e;i++)
	 if (getfa(a[i].x)!=getfa(a[i].y)){
	 	val[++N]=a[i].h;
	 	add(N,getfa(a[i].x),0,1); add(N,getfa(a[i].y),0,1);
	 	fa[getfa(a[i].x)]=N; fa[getfa(a[i].y)]=N;
	 }
}
void dfs(int x){
	MIN[x]=dst[x];
	for (int j=lnk[1][x];j;j=nxt[j])
	 f[son[j]][0]=x,dfs(son[j]),MIN[x]=min(MIN[x],MIN[son[j]]);
}
void DP(){
	for (int j=1;j<20;j++)
	 for (int i=1;i<=N;i++)
	  f[i][j]=f[f[i][j-1]][j-1];
}
int main(){
	tst=red();
	while (tst--){
		n=red(),e=red();
		tot=0;cl(lnk,0);
		for (int i=1;i<=e;i++){
			a[i].x=red(),a[i].y=red(),a[i].w=red(),a[i].h=red();
			add(a[i].x,a[i].y,a[i].w,0);add(a[i].y,a[i].x,a[i].w,0);
		}
		DIJ(); kruskal(); f[N][0]=N; dfs(N); DP();
		q=red(),K=red(),S=red();int lastans=0;
		for (int i=1,x,h;i<=q;i++){
			x=(red()+K*lastans%n-1)%n+1,h=(red()+K*lastans%(S+1))%(S+1);
			for (int j=19;j>=0;j--)
			 if (val[f[x][j]]>h) x=f[x][j];
			printf("%d\n",lastans=MIN[x]);
		}
	}
	return 0;
}
