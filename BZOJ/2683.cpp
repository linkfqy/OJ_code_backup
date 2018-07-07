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

const int maxn=800005;
int n,q;
bool vis[maxn];
struct data{
	int t,x,y,w;
	inline bool operator<(const data&b)const {return x<b.x || x==b.x&&y<b.y || x==b.x&&y==b.y&&t<b.t;}
}a[maxn],t[maxn];
#define lowbit(x) ((x)&-(x))
ll BIT[maxn],ans[maxn];
inline void ist(int x,int w){
	for (int i=x;i<=n;i+=lowbit(i)) BIT[i]+=w;
}
inline ll ask(int x){
	ll res=0;
	for (int i=x;i;i-=lowbit(i)) res+=BIT[i];
	return res;
}
void CDQ(int l,int r){
	if (l==r) return;
	int mid=l+r>>1;
	CDQ(l,mid);CDQ(mid+1,r);
	for (int i=l;i<=r;i++){
		t[i]=a[i];
		if (i<=mid) t[i].t=0;
	}
	sort(t+l,t+1+r);
	for (int i=l;i<=r;i++){
		if (!t[i].t&&t[i].w) ist(t[i].y,t[i].w);
		if (t[i].t&&!t[i].w) ans[t[i].t]+=ask(t[i].y);
	}
	for (int i=l;i<=r;i++) if (!t[i].t&&t[i].w) ist(t[i].y,-t[i].w);
}
int main(){
	n=red()+1;
	for (int c=red();c!=3;c=red())
	 if (c==1){
	 	a[++q].x=red()+1,a[q].y=red()+1;
	 	a[q].t=q;a[q].w=red();vis[q]=1;
	 }else{
	 	int x=red()+1,y=red()+1,xx=red()+1,yy=red()+1;
	 	a[++q].x=xx;a[q].y=yy;a[q].t=q;
	 	a[++q].x=xx;a[q].y=y-1;a[q].t=q;
	 	a[++q].x=x-1;a[q].y=yy;a[q].t=q;
	 	a[++q].x=x-1;a[q].y=y-1;a[q].t=q;
	 }
	CDQ(1,q);
	for (int i=1;i<=q;i++)
	 if (!vis[i]) printf("%lld\n",ans[i]-ans[i+1]-ans[i+2]+ans[i+3]),i+=3;
	return 0;
}
