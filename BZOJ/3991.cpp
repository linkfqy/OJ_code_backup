#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
typedef set<int>::iterator iter;
typedef long long ll;

const int maxn=100005,maxe=200005;
int n,q;
int tot,son[maxe],nxt[maxe],lnk[maxn],w[maxe];
inline void add(int x,int y,int z){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=z;
}
int dep[maxn],dfn[maxn],id[maxn],f[maxn][18];ll g[maxn][18],times;
bool imp[maxn]; 
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;f[x][0]=fa;dfn[x]=++times;id[times]=x;
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa) g[son[j]][0]=w[j],dfs(son[j],x);
}
void DP(){
	for (int j=1;j<=17;j++)
	 for (int i=1;i<=n;i++)
	  f[i][j]=f[f[i][j-1]][j-1],
	  g[i][j]=g[i][j-1]+g[f[i][j-1]][j-1];
}
ll dst(int x,int y){
	ll res=0;
	if (dep[x]<dep[y]) swap(x,y);
	for (int j=17;~j;j--)
	 if (dep[f[x][j]]>=dep[y]) res+=g[x][j],x=f[x][j];
	if (x==y) return res;
	for (int j=17;~j;j--)
	 if (f[x][j]!=f[y][j]) res+=g[x][j]+g[y][j],x=f[x][j],y=f[y][j];
	return res+g[x][0]+g[y][0];
}
set<int> S;
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1,x,y,z;i<n;i++) scanf("%d%d%d",&x,&y,&z),add(x,y,z),add(y,x,z);
	dfs(1,1); DP();
	ll ans=0;
	while (q--){
		int x;scanf("%d",&x);
		if (imp[x]){
			iter l,r;
			if (S.size()>1){
				l=S.find(dfn[x]); r=l;r++;
				if (l==S.begin()) l=S.end();l--;
				if (r==S.end()) r=S.begin();
				ans-=dst(id[*l],x)+dst(id[*r],x);
			}
			if (S.size()>2) ans+=dst(id[*l],id[*r]);
			S.erase(dfn[x]);
		}else{
			iter l,r;
			S.insert(dfn[x]);
			if (S.size()>1){
				l=S.find(dfn[x]); r=l;r++;
				if (l==S.begin()) l=S.end();l--;
				if (r==S.end()) r=S.begin();
				ans+=dst(id[*l],x)+dst(id[*r],x);
			}
			if (S.size()>2) ans-=dst(id[*l],id[*r]);
		}
		imp[x]^=1;
		printf("%lld\n",ans);
	}
}
