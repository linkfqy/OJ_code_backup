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

const int maxn=500005,maxs=1000005,INF=0x3f3f3f3f;
int n,q,m,a[maxn],b[maxn],w[maxn];
int BIT[maxn];
#define lowbit(x) ((x)&-(x))
void ist(int x,int w){
	for (int i=x;i<=m;i+=lowbit(i)) BIT[i]+=w;
}
int qry(int x){
	int res=0;
	for (int i=x;i;i-=lowbit(i)) res+=BIT[i];
	return res;
}
int mn[maxs];ll ans;
#define ls x<<1
#define rs x<<1|1
void build(int x,int l,int r){
	if (l==r) {mn[x]=a[l];return;}
	int mid=l+r>>1;
	build(ls,l,mid);build(rs,mid+1,r);
	mn[x]=min(mn[ls],mn[rs]);
}
void solve(int x,int l,int r,int ql,int qr,int ww){
	if (mn[x]>ww||qr<l||r<ql) return;
	if (l==r) {ans-=w[l];mn[x]=INF;return;}
	int mid=l+r>>1;
	solve(ls,l,mid,ql,qr,ww);
	solve(rs,mid+1,r,ql,qr,ww);
	mn[x]=min(mn[ls],mn[rs]);
}
int main(){
	n=red(),q=red();
	for (int i=1;i<=n;i++) a[i]=b[i]=red();
	sort(b+1,b+1+n); m=unique(b+1,b+1+n)-b-1;
	for (int i=n;i>=1;i--){
		a[i]=lower_bound(b+1,b+1+m,a[i])-b;
		ist(a[i],1);
		w[i]=qry(a[i]-1);ans+=w[i];
	}
	build(1,1,n);
	printf("%lld\n",ans);
	while (q--){
		int x=red();
		solve(1,1,n,x,n,a[x]);
		printf("%lld\n",ans);
	}
	return 0;
}
