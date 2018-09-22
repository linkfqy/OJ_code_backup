#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100005,maxe=300005;
int n,e,ans[maxe];
struct data{
	int x,y,w,id;
	data () {}
	data (int _x,int _y,int _w):x(_x),y(_y),w(_w) {}
	bool operator<(const data&b)const {return w<b.w;}
}a[maxe],b[maxe];
int fa[maxn],siz[maxn],dep[maxn],del[maxe],depp[maxe],X[maxe],Y[maxe],ji,len;
inline int getfa(int x) {return fa[x]==x?x:getfa(fa[x]);}
inline void merge(int x,int y){
	x=getfa(x);y=getfa(y);
	if (x==y) return;
	if (dep[x]<dep[y]) swap(x,y);
	++len;
	if ((siz[x]&1)&&(siz[y]&1)) del[len]=-2,ji-=2;
	 else del[len]=0;
	X[len]=x;Y[len]=y; depp[len]=dep[y];
	siz[x]+=siz[y];dep[x]=max(dep[x],dep[y]+1); fa[y]=x;
}
inline void undo(){
	ji-=del[len]; dep[X[len]]=depp[len];
	siz[X[len]]-=siz[Y[len]]; fa[Y[len]]=Y[len];
	len--;
}
void solve(int ql,int qr,int l,int r){
	if (ql>qr) return;
	int mid=ql+qr>>1,ans_mid=0;
	
	int t1=len;
	for (int i=ql;i<=mid;i++)
	 if (a[i].w<l) merge(a[i].x,a[i].y);
	for (int i=l;i<=r;i++){
		if (b[i].id<=mid) merge(b[i].x,b[i].y);
		if (ji==0) {ans_mid=i;break;}
	}
	
	while (len>t1) undo();
	if (!ans_mid){
		for (int i=ql;i<=mid;i++){
			ans[i]=-1;
			if (a[i].w<l) merge(a[i].x,a[i].y);
		}
		solve(mid+1,qr,l,r);
	}else{
		ans[mid]=b[ans_mid].w;
		for (int i=l;i<ans_mid;i++)
		 if (b[i].id<ql) merge(b[i].x,b[i].y);
		solve(ql,mid-1,ans_mid,r);
		while (len>t1) undo();
		for (int i=ql;i<=mid;i++)
		 if (a[i].w<l) merge(a[i].x,a[i].y);
		solve(mid+1,qr,l,ans_mid);
	}
	while (len>t1) undo();
}
int main(){
	scanf("%d%d",&n,&e);
	ji=n; for (int i=1;i<=n;i++) fa[i]=i,dep[i]=siz[i]=1;
	for (int i=1;i<=e;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w),a[i].id=i,b[i]=a[i];
	sort(b+1,b+1+e);
	for (int i=1;i<=e;i++) a[b[i].id].w=i;
	solve(1,e,1,e);
	for (int i=1;i<=e;i++) printf("%d\n",ans[i]);
	return 0;
}
