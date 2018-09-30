#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
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

const int maxn=1000005,maxs=4000005;
int tst,n,q,a[maxn];
int mx[maxs],sd[maxs],t[maxs],tg[maxs];ll s[maxs];
#define ls x<<1
#define rs x<<1|1
inline void pushup(int x){
	s[x]=s[ls]+s[rs];
	if (mx[ls]<mx[rs]) mx[x]=mx[rs],t[x]=t[rs],sd[x]=max(mx[ls],sd[rs]);else
	if (mx[ls]>mx[rs]) mx[x]=mx[ls],t[x]=t[ls],sd[x]=max(mx[rs],sd[ls]);else
	mx[x]=mx[ls],t[x]=t[ls]+t[rs],sd[x]=max(sd[ls],sd[rs]);
}
inline void addtg(int x,int w){
	if (w>=mx[x]) return;
	s[x]+=(ll)t[x]*(w-mx[x]);mx[x]=w;tg[x]=w;
}
inline void pushdown(int x){
	if (tg[x]>=0) addtg(ls,tg[x]),addtg(rs,tg[x]),tg[x]=-1;
}
void build(int x,int l,int r){
	tg[x]=-1;
	if (l==r) {mx[x]=s[x]=a[l];t[x]=1;sd[x]=-1;return;}
	int mid=l+r>>1;
	build(ls,l,mid);build(rs,mid+1,r);
	pushup(x);
}
void istmin(int x,int l,int r,int ql,int qr,int w){
	if (qr<l||r<ql||mx[x]<=w) return;
	if (ql<=l&&r<=qr&&sd[x]<w) {addtg(x,w);return;}
	int mid=l+r>>1; pushdown(x);
	istmin(ls,l,mid,ql,qr,w);istmin(rs,mid+1,r,ql,qr,w);
	pushup(x);
}
ll qrys(int x,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr) return s[x];
	if (qr<l||r<ql) return 0;
	int mid=l+r>>1; pushdown(x);
	return qrys(ls,l,mid,ql,qr)+qrys(rs,mid+1,r,ql,qr);
}
int qrymx(int x,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr) return mx[x];
	if (qr<l||r<ql) return 0;
	int mid=l+r>>1; pushdown(x);
	return max(qrymx(ls,l,mid,ql,qr),qrymx(rs,mid+1,r,ql,qr));
}
int main(){
	tst=red();
	while (tst--){
		n=red(),q=red();
		for (int i=1;i<=n;i++) a[i]=red();
		build(1,1,n);
		while (q--){
			int c=red();
			if (c==0){
				int l=red(),r=red(),w=red();
				istmin(1,1,n,l,r,w);
			}else
			if (c==1){
				int l=red(),r=red();
				printf("%d\n",qrymx(1,1,n,l,r));
			}else{
				int l=red(),r=red();
				printf("%lld\n",qrys(1,1,n,l,r));
			}
		}
	}
	return 0;
}
