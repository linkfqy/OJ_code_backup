#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

const int maxn=200005,maxs=800005,INF=0x3f3f3f3f;
int n,K,d,a[maxn];
struct data{
	int l,r;
	data () {}
	data (int _l,int _r):l(_l),r(_r) {}
	bool operator<(const data&b)const {return r-l>b.r-b.l||r-l==b.r-b.l&&l<b.l;}
}ans(1,1);
int mn[maxs],ad[maxs],Ret;
inline void pushup(int x) {mn[x]=min(mn[x<<1],mn[x<<1|1]);}
inline void addad(int x,int w) {mn[x]+=w;ad[x]+=w;}
inline void pushdown(int x) {if (ad[x]) addad(x<<1,ad[x]),addad(x<<1|1,ad[x]),ad[x]=0;}
void build(int x,int l,int r){
	if (l==r) {mn[x]=-r;return;}
	int mid=l+r>>1;
	build(x<<1,l,mid); build(x<<1|1,mid+1,r);
	pushup(x);
}
void ist(int x,int l,int r,int ql,int qr,int w){
	if (ql<=l&&r<=qr) {addad(x,w);return;}
	if (qr<l||r<ql) return;
	int mid=l+r>>1; pushdown(x);
	ist(x<<1,l,mid,ql,qr,w); ist(x<<1|1,mid+1,r,ql,qr,w);
	pushup(x);
}
void qry(int x,int l,int r,int K){
	if (l==r) {Ret=l;return;}
	int mid=l+r>>1; pushdown(x);
	if (mn[x<<1|1]<=K) qry(x<<1|1,mid+1,r,K);else qry(x<<1,l,mid,K);
}
void query(int x,int l,int r,int ql,int qr,int K){
	if (Ret) return;
	if (ql<=l&&r<=qr) {if (mn[x]<=K) qry(x,l,r,K);return;}
	if (qr<l||r<ql) return;
	int mid=l+r>>1; pushdown(x);
	query(x<<1|1,mid+1,r,ql,qr,K); query(x<<1,l,mid,ql,qr,K);
}
map<int,int> nxt;
int stk1[maxn],stk2[maxn],top1,top2,far;
void solve(const int&l,const int&r){
	if (l==r) return;
	for (int i=l;i<=r;i++) a[i]=(a[i]+1e9)/d+1;
	top1=top2=0; stk1[0]=stk2[0]=far=r+1;
	nxt.clear();
	for (int i=r;i>=l;i--){
		if (nxt.count(a[i])) far=min(far,nxt[a[i]]);
		nxt[a[i]]=i;
		while (top1&&a[stk1[top1]]>=a[i]){
			ist(1,1,n,stk1[top1],stk1[top1-1]-1,a[stk1[top1]]);
			top1--;
		}
		stk1[++top1]=i;
		ist(1,1,n,stk1[top1],stk1[top1-1]-1,-a[i]);
		
		while (top2&&a[stk2[top2]]<=a[i]){
			ist(1,1,n,stk2[top2],stk2[top2-1]-1,-a[stk2[top2]]);
			top2--;
		}
		stk2[++top2]=i;
		ist(1,1,n,stk2[top2],stk2[top2-1]-1,a[i]);
		
		Ret=0; query(1,1,n,i,far-1,K-i);
		ans=min(ans,data(i,Ret));
	}
}
int main(){
	scanf("%d%d%d",&n,&K,&d);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	if (d==0){
		for (int i=1,j=1;i<=n;i=j){
			while (j<=n&&a[i]==a[j]) j++;
			ans=min(ans,data(i,j-1));
		}
		printf("%d %d",ans.l,ans.r);
		return 0;
	}
	build(1,1,n);
	for (int i=1,j=1;i<=n;i=j){
		while (j<=n&&(a[i]%d+d)%d==(a[j]%d+d)%d) j++;
		solve(i,j-1);
	}
	printf("%d %d",ans.l,ans.r);
	return 0;
}
