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

const int maxn=500005,maxs=8*maxn,INF=0x3f3f3f3f;
int n,m,b[maxn*2],N;
struct data{
	int l,r,w;
	inline bool operator<(const data&b)const {return w<b.w;}
}a[maxn];
int mx[maxs],ad[maxs];
inline void pushup(int x) {mx[x]=max(mx[x<<1],mx[x<<1|1]);}
inline void addad(int x,int w) {mx[x]+=w;ad[x]+=w;}
inline void pushdown(int x) {if (ad[x]){addad(x<<1,ad[x]);addad(x<<1|1,ad[x]);ad[x]=0;}}
void ist(int x,int l,int r,int ql,int qr,int w){
	if (ql<=l&&r<=qr) {addad(x,w);return;}
	if (qr<l||r<ql) return;
	int mid=l+r>>1; pushdown(x);
	ist(x<<1,l,mid,ql,qr,w); ist(x<<1|1,mid+1,r,ql,qr,w);
	pushup(x);
}
int qry(int x,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr) return mx[x];
	if (qr<l||r<ql) return 0;
	int mid=l+r>>1; pushdown(x);
	return max(qry(x<<1,l,mid,ql,qr),qry(x<<1|1,mid+1,r,ql,qr));
}
int main(){
	n=red(),m=red();
	for (int i=1;i<=n;i++) b[++N]=a[i].l=red(),b[++N]=a[i].r=red(),a[i].w=a[i].r-a[i].l;
	sort(b+1,b+1+N); N=unique(b+1,b+1+N)-b-1;
	for (int i=1;i<=n;i++) a[i].l=lower_bound(b+1,b+1+N,a[i].l)-b,a[i].r=lower_bound(b+1,b+1+N,a[i].r)-b;
	sort(a+1,a+1+n);
	int ans=INF;
	for (int i=1,j=0;i<=n;i++){
		while (mx[1]<m&&j<n) j++,ist(1,1,N,a[j].l,a[j].r,1);
		if (mx[1]>=m) ans=min(ans,a[j].w-a[i].w);
		ist(1,1,N,a[i].l,a[i].r,-1);
	}
	if (ans==INF) return puts("-1"),0;
	printf("%d",ans);
	return 0;
}
