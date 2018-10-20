#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;

const int maxn=80005,maxe=3000005,maxs=80005,INF=0x3f3f3f3f;
int n,q,N,m,S,T,a[maxn];
struct event{
	int x,l,r,f;
	event(int _x=0,int _l=0,int _r=0,int _f=0):x(_x),l(_l),r(_r),f(_f) {}
	bool operator<(const event&b)const{
		return x<b.x||x==b.x&&f>b.f;
	}
}E[maxs];
int son[maxe],nxt[maxe],lnk[maxn],flw[maxe],cap[maxe],tot=1;
inline void add(int x,int y,int f){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;flw[tot]=0;cap[tot]=f;
	son[++tot]=x;nxt[tot]=lnk[y];lnk[y]=tot;flw[tot]=0;cap[tot]=0;
}
int d[maxn],que[maxn],pos[maxn];
bool bfs(){
	cl(d,63);
	int hed=0,til=1;
	que[1]=S;d[S]=0;
	while (hed!=til){
		int x=que[++hed];
		for (int j=lnk[x];j;j=nxt[j])
		 if (d[son[j]]==INF&&flw[j]<cap[j])
		  d[que[++til]=son[j]]=d[x]+1;
	}
	return d[T]!=INF;
}
int dfs(int x,int flow){
	if (x==T||flow==0) return flow;
	int res=0,f;
	for (int &j=pos[x];j;j=nxt[j])
	 if (d[son[j]]==d[x]+1&&(f=dfs(son[j],min(flow,cap[j]-flw[j])))>0){
	 	flw[j]+=f; flw[j^1]-=f;
	 	res+=f; flow-=f;
	 	if (flow==0) break;
	 }
	return res;
}
int dinic(){
	int ans=0;
	while (bfs()){
		memcpy(pos,lnk,sizeof(lnk));
		ans+=dfs(S,INF);
	}
	return ans;
}
int ls[maxs],rs[maxs],Rx,Ry;
void build(int &x,int l,int r,int d){
	x=++N;
	if (l==r){
		if (d) add(x,T,1);else add(S,x,1);
		return;
	}
	int mid=l+r>>1;
	build(ls[x],l,mid,d);build(rs[x],mid+1,r,d);
	if (d) add(x,ls[x],INF),add(x,rs[x],INF);
	  else add(ls[x],x,INF),add(rs[x],x,INF);
}
void qry(int x,int l,int r,int ql,int qr,int z,int d){
	if (ql<=l&&r<=qr){
		if (d) add(z,x,INF);else add(x,z,INF);
		return;
	}
	if (qr<l||r<ql) return;
	int mid=l+r>>1;
	qry(ls[x],l,mid,ql,qr,z,d);qry(rs[x],mid+1,r,ql,qr,z,d);
}
void cover(int x,int l,int r){
	for (int i=l;i<=r;i++) a[i]=x;
}
void work(int x,int l,int r){
	for (int i=l,j=l;i<=r;i=j){
		while (j<=r&&a[i]==a[j]) j++;
		N++;//printf("%d %d %d %d\n",a[i]+1,i,x,j-1);
		qry(Rx,1,n,a[i]+1,x,N,0);
		qry(Ry,1,n,i,j-1,N,1);
	}
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=q;i++){
		int x,y,xx,yy;scanf("%d%d%d%d",&x,&y,&xx,&yy);
		E[++m]=event(x-1,y,yy,0); E[++m]=event(xx,y,yy,1);
	}
	S=++N;T=++N;
	build(Rx,1,n,0);build(Ry,1,n,1);
	sort(E+1,E+1+m);
	for (int i=1;i<=m;i++)
	 if (E[i].f) cover(E[i].x,E[i].l,E[i].r);else work(E[i].x,E[i].l,E[i].r);
	work(n,1,n);
	printf("%d",dinic());
	return 0;
}
