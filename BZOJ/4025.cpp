#include<cstdio>
#include<vector>
#include<algorithm>
#define pb push_back
using namespace std;

const int maxn=100005,maxe=200005,maxs=200005;
int n,e,T;
int fa[maxn],c[maxn],rk[maxn],rkk[maxs],X[maxs],Y[maxs],cc[maxs],len;
inline void ufs_init(){
	len=0;
	for (int i=1;i<=n;i++) fa[i]=i,rk[i]=1;
}
inline int getfa(int x) {while (fa[x]!=x) x=fa[x];return x;}
inline int dis(int x){
	int res=0;
	while (fa[x]!=x) res^=c[x],x=fa[x];
	return res;
}
inline void merge(int x,int y,int w){
	x=getfa(x); y=getfa(y);
	if (x==y) return;
	if (rk[x]<rk[y]) swap(x,y);
	len++;
	X[len]=x; Y[len]=y; rkk[len]=rk[x]; cc[len]=c[y];
	fa[y]=x; rk[x]=max(rk[x],rk[y]+1); c[y]=w;
}
inline void undo(){
	rk[X[len]]=rkk[len]; c[Y[len]]=cc[len];
	fa[Y[len]]=Y[len];
	len--;
}
struct data{
	int x,y,s,t;
	data () {}
	data (int _x,int _y,int _s,int _t):x(_x),y(_y),s(_s),t(_t) {}
};
void solve(int l,int r,vector<data> &v){
	vector<data> lv,rv;
	vector<data>:: iterator it;
	int mid=l+r>>1,tag=len;
	for (it=v.begin();it!=v.end();it++)
	 if (it->s==l&&it->t==r){
	 	int w=dis(it->x)^dis(it->y)^1;
	 	if (getfa(it->x)!=getfa(it->y)) merge(it->x,it->y,w);
	 	else if (w&1){
	 		for (int i=l;i<=r;i++) puts("No");
	 		while (len>tag) undo();
	 		return;
		}
	 }else
	 if (it->t <=mid) lv.pb(*it);else
	 if (it->s > mid) rv.pb(*it);else
	  lv.pb(data(it->x,it->y,it->s,mid)),rv.pb(data(it->x,it->y,mid+1,it->t));
	if (l==r) puts("Yes");
	else solve(l,mid,lv),solve(mid+1,r,rv);
	while (len>tag) undo();
}
int main(){
	scanf("%d%d%d",&n,&e,&T);
	ufs_init(); vector<data> v;
	for (int i=1,x,y,s,t;i<=e;i++){
		scanf("%d%d%d%d",&x,&y,&s,&t);
		s++; if (s>t) continue;
		v.pb(data(x,y,s,t));
	}
	solve(1,T,v);
	return 0;
}
