#include<cstdio>
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

const int maxn=100005;
int n,tt,m,a[maxn],where[maxn];
ll ans[maxn];
bool vis[maxn];
#define lowbit(x) ((x)&-(x))
int BIT[maxn];
inline void ist(int x,int w){
	for (int i=x;i<=n;i+=lowbit(i)) BIT[i]+=w;
}
inline int ask(int x){
	int res=0;
	for (int i=x;i;i-=lowbit(i)) res+=BIT[i];
	return res;
}
struct data{
	int p,x,t;
	bool operator<(const data&b)const{return p<b.p;}
}q[maxn],t[maxn];
void CDQ(int l,int r){
	if (l==r) return;
	int mid=l+r>>1;
	CDQ(l,mid);CDQ(mid+1,r);
	for (int i=l;i<=r;i++){
		t[i]=q[i];
		if (i>mid) t[i].t=0;
	}
	sort(t+l,t+r+1);
	for (int i=l;i<=r;i++)
	 if (!t[i].t) ist(t[i].x,1);
	 else ans[t[i].t]+=ask(n)-ask(t[i].x);
	for (int i=l;i<=r;i++) if (!t[i].t) ist(t[i].x,-1);
	for (int i=r;i>=l;i--)
	 if (!t[i].t) ist(t[i].x,1);
	 else ans[t[i].t]+=ask(t[i].x);
	for (int i=l;i<=r;i++) if (!t[i].t) ist(t[i].x,-1);
}
int main(){
	n=red(),tt=m=red();
	for (int i=1;i<=n;i++) a[i]=red(),where[a[i]]=i;
	for (int i=1;i<=m;i++){
		q[i].x=red();
		q[i].p=where[q[i].x];
		vis[q[i].p]=1,q[i].t=i;
	}
	for (int i=1;i<=n;i++)
	 if (!vis[i]) q[++m].x=a[i],q[m].p=i,q[m].t=m;
	CDQ(1,n);
	for (int i=n-1;i;i--) ans[i]+=ans[i+1];
	for (int i=1;i<=tt;i++) printf("%lld\n",ans[i]);
	return 0;
}
