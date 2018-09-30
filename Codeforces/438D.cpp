#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=100005,maxs=400005;
int n,q,a[maxn];
int mx[maxs];ll s[maxs];
inline void pushup(int x) {mx[x]=max(mx[x<<1],mx[x<<1|1]);s[x]=s[x<<1]+s[x<<1|1];}
void build(int x,int l,int r){
	if (l==r) {mx[x]=s[x]=a[l];return;}
	int mid=l+r>>1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	pushup(x);
}
void istmod(int x,int l,int r,int ql,int qr,int w){
	if (mx[x]<w) return;
	if (qr<l||r<ql) return;
	if (l==r) {mx[x]=s[x]=(s[x]%w);return;}
	int mid=l+r>>1;
	istmod(x<<1,l,mid,ql,qr,w);istmod(x<<1|1,mid+1,r,ql,qr,w);
	pushup(x);
}
void ist(int x,int l,int r,int k,int w){
	if (l==r) {mx[x]=s[x]=w;return;}
	int mid=l+r>>1;
	if (k<=mid) ist(x<<1,l,mid,k,w);else ist(x<<1|1,mid+1,r,k,w);
	pushup(x);
}
ll qry(int x,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr) return s[x];
	if (qr<l||r<ql) return 0;
	int mid=l+r>>1;
	return qry(x<<1,l,mid,ql,qr)+qry(x<<1|1,mid+1,r,ql,qr);
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n);
	while (q--){
		int c;scanf("%d",&c);
		if (c==1){
			int l,r;scanf("%d%d",&l,&r);
			printf("%lld\n",qry(1,1,n,l,r));
		}else
		if (c==2){
			int l,r,w;scanf("%d%d%d",&l,&r,&w);
			istmod(1,1,n,l,r,w);
		}else{
			int k,w;scanf("%d%d",&k,&w);
			ist(1,1,n,k,w);
		}
	}
	return 0;
}
