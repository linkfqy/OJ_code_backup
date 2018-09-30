#include<cstdio>
typedef long long ll;

const int maxn=300005,maxs=1200005,maxp=1e7+5;
int tst,n,q,a[maxn],phi[maxp],p[maxp];
bool vis[maxp];
void makep(int n){
	phi[1]=1;
	for (int i=2;i<=n;i++){
		if (!vis[i]) p[++p[0]]=i,phi[i]=i-1;
		for (int j=1;j<=p[0]&&i*p[j]<=n;j++){
			vis[i*p[j]]=1;
			if (i%p[j]==0) {phi[i*p[j]]=phi[i]*p[j];break;}else phi[i*p[j]]=phi[i]*phi[p[j]];
		}
	}
}
ll s[maxs];int sm[maxs],cv[maxs];
inline void pushup(int x){
	s[x]=s[x<<1]+s[x<<1|1];
	if (sm[x<<1]==sm[x<<1|1]) sm[x]=sm[x<<1];else sm[x]=0;
}
inline void addcv(int x,int l,int r,int w) {s[x]=(ll)w*(r-l+1);sm[x]=w;cv[x]=w;}
inline void pushdown(int x,int l,int r,int mid){
	if (cv[x]) addcv(x<<1,l,mid,cv[x]),addcv(x<<1|1,mid+1,r,cv[x]),cv[x]=0;
}
void build(int x,int l,int r){
	cv[x]=0;
	if (l==r) {s[x]=sm[x]=a[l];return;}
	int mid=l+r>>1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	pushup(x);
}
void ist(int x,int l,int r,int ql,int qr){
	if (sm[x]&&ql<=l&&r<=qr){addcv(x,l,r,phi[sm[x]]);return;}
	if (qr<l||r<ql) return;
	int mid=l+r>>1;pushdown(x,l,r,mid);
	ist(x<<1,l,mid,ql,qr),ist(x<<1|1,mid+1,r,ql,qr);
	pushup(x);
}
void change(int x,int l,int r,int ql,int qr,int w){
	if (ql<=l&&r<=qr) {addcv(x,l,r,w);return;}
	if (qr<l||r<ql) return;
	int mid=l+r>>1;pushdown(x,l,r,mid);
	change(x<<1,l,mid,ql,qr,w); change(x<<1|1,mid+1,r,ql,qr,w);
	pushup(x);
}
ll qry(int x,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr) return s[x];
	if (qr<l||r<ql) return 0;
	int mid=l+r>>1;pushdown(x,l,r,mid);
	return qry(x<<1,l,mid,ql,qr)+qry(x<<1|1,mid+1,r,ql,qr);
}
int main(){
	makep(1e7);
	scanf("%d",&tst);
	while (tst--){
		scanf("%d%d",&n,&q);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		build(1,1,n);
		while (q--){
			int c;scanf("%d",&c);
			if (c==1){
				int l,r;scanf("%d%d",&l,&r);
				ist(1,1,n,l,r);
			}else
			if (c==2){
				int l,r,w;scanf("%d%d%d",&l,&r,&w);
				change(1,1,n,l,r,w);
			}else{
				int l,r;scanf("%d%d",&l,&r);
				printf("%lld\n",qry(1,1,n,l,r));
			}
		}
	}
	return 0;
}
