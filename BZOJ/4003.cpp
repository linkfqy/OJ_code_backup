#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=300005,maxe=300005;
int n,m,a[maxn],c[maxn],ans[maxn*2];
ll h[maxn],v[maxn];
int son[maxe],lnk[maxn],nxt[maxe],tot;
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
int ls[maxn],rs[maxn],rt[maxn],id[maxn];ll key[maxn],ad[maxn],ml[maxn];
inline void addad(int x,ll w) {if (x) key[x]+=w,ad[x]+=w;}
inline void addml(int x,ll w) {if (x) key[x]*=w,ml[x]*=w,ad[x]*=w;}
inline void pushdown(int x){
	if (ml[x]!=1) addml(ls[x],ml[x]),addml(rs[x],ml[x]),ml[x]=1;
	if (ad[x]!=0) addad(ls[x],ad[x]),addad(rs[x],ad[x]),ad[x]=0;
}
int merge(int a,int b){
	if (!a||!b) return a+b;
	if (key[a]>key[b]) swap(a,b);
	pushdown(a);pushdown(b);
	if (rand()&1) ls[a]=merge(ls[a],b);else rs[a]=merge(rs[a],b);
	return a;
}
int del(int a){
	if (!a) return 0;
	pushdown(a);
	return merge(ls[a],rs[a]);
}
int dep[maxn];
void dfs(int x){
	for (int j=lnk[x];j;j=nxt[j]){
		dep[son[j]]=dep[x]+1; dfs(son[j]);
		rt[x]=merge(rt[son[j]],rt[x]);
	}
	while (rt[x]&&key[rt[x]]<h[x]){
		ans[x]++; ans[rt[x]+n]=dep[c[rt[x]]]-dep[x];
		rt[x]=del(rt[x]);
	}
	if (a[x]==0) addad(rt[x],v[x]);
	else addml(rt[x],v[x]);
}
int main(){
	srand(19260817);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&h[i]);
	for (int i=2,x;i<=n;i++) scanf("%d%d%lld",&x,&a[i],&v[i]),add(x,i);
	key[0]=1e18;
	for (int i=1;i<=m;i++){
		int x;
		scanf("%lld%d",&key[i],&x);ad[i]=0;ml[i]=1;
		c[i]=x;	rt[x]=merge(rt[x],i);
	}
	dfs(1);
	while (rt[1]){
		ans[rt[1]+n]=dep[c[rt[1]]]+1;
		rt[1]=del(rt[1]);
	}
	for (int i=1;i<=n+m;i++) printf("%d\n",ans[i]);
	return 0;
}
