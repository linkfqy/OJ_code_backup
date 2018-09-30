#include<cstdio>
typedef long long ll;

const int maxn=100005,maxs=400005;
int n,q; char s[10];
ll w[maxs],wi[maxs],wii[maxs],i[maxs],ii[maxs],ad[maxs];
#define ls x<<1
#define rs x<<1|1
inline void pushup(int x){
	w[x]=w[ls]+w[rs];
	wi[x]=wi[ls]+wi[rs];
	wii[x]=wii[ls]+wii[rs];
	i[x]=i[ls]+i[rs];
	ii[x]=ii[ls]+ii[rs];
}
inline void addad(int x,ll v,int l,int r){
	w[x]+=v*(r-l+1);
	wi[x]+=v*i[x];
	wii[x]+=v*ii[x];
	ad[x]+=v;
}
inline void pushdown(int x,int l,int mid,int r){
	if (ad[x]) addad(ls,ad[x],l,mid),addad(rs,ad[x],mid+1,r),ad[x]=0;
}
void build(int x,int l,int r){
	if (l==r) {i[x]=l;ii[x]=(ll)l*l;return;}
	int mid=l+r>>1;
	build(ls,l,mid);build(rs,mid+1,r);
	pushup(x);
}
void ist(int x,int l,int r,int ql,int qr,int v){
	if (ql<=l&&r<=qr) {addad(x,v,l,r);return;}
	if (qr<l||r<ql) return;
	int mid=l+r>>1; pushdown(x,l,mid,r);
	ist(ls,l,mid,ql,qr,v);ist(rs,mid+1,r,ql,qr,v);
	pushup(x);
}
ll qry(int x,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr) return (ql+qr)*wi[x]-wii[x]-w[x]*((ll)ql*qr+ql-qr-1);
	if (qr<l||r<ql) return 0;
	int mid=l+r>>1; pushdown(x,l,mid,r);
	return qry(ls,l,mid,ql,qr)+qry(rs,mid+1,r,ql,qr);
}
ll gcd(ll x,ll y) {return y==0?x:gcd(y,x%y);}
int main(){
	scanf("%d%d",&n,&q);
	build(1,1,n);
	while (q--){
		scanf("%s",s);
		if (s[0]=='C'){
			int l,r,v;scanf("%d%d%d",&l,&r,&v);r--;
			ist(1,1,n,l,r,v);
		}else{
			int l,r;scanf("%d%d",&l,&r);r--;
			ll k=r-l+1,a=qry(1,1,n,l,r),b=k*(k+1)/2;
			ll t=gcd(a,b); a/=t;b/=t;
			printf("%lld/%lld\n",a,b);
		}
	}
	return 0;
}
