#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
inline char nc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int red(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
	return res*f;
}

const int maxn=1000005;
int n,m;
ll f[maxn];
struct data{
	ll l,r;
	bool operator<(const data&b)const{
		return l<b.l||l==b.l&&r>b.r;
	}
}a[maxn],b[maxn];
void divide(int l,int r,int ql,int qr){
	if (ql>qr) return;
	int mid=ql+qr>>1;
	int pos=0,i=mid;ll w=0;
	for (int j=l;j<=r&&j<i;j++)
	 if (a[i].l<a[j].r&&w<(a[i].r-a[j].l)*(a[j].r-a[i].l)) w=(a[i].r-a[j].l)*(a[j].r-a[i].l),pos=i;
	f[i]=w;
	if (!pos) divide(l,r,ql,mid-1),divide(l,r,mid+1,qr);
	else divide(l,pos,ql,mid-1),divide(pos,r,mid+1,qr);
}
int main(){
	n=red();
	for (int i=1;i<=n;i++) b[i].l=red(),b[i].r=red();
	sort(b+1,b+1+n);
	a[m=1]=b[1];
	ll ans=0;int x=1,maxr=b[1].r;
	for (int i=2;i<=n;i++)
	 if (maxr<b[i].r) a[++m]=b[i],x=i,maxr=b[i].r;
	 else ans=max(ans,(b[x].r-b[x].l)*(b[i].r-b[i].l));
	n=m;
	divide(1,n,1,n);
	for (int i=2;i<=n;i++) ans=max(ans,f[i]);
	printf("%lld",ans);
	return 0;
}
