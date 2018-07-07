#include<cstdio>
#define lowbit(x) ((x)&-(x))
typedef long long ll;
inline char nc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int red(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=(res<<3)+(res<<1)+ch-48,ch=nc();
	return res*f;
}

const int maxn=100005,maxe=100005;
int n,in[maxn],out[maxn],BIT[maxn],tim;
ll ans;
void ist(int x,int w){
	for (int i=x;i<=n;i+=lowbit(i)) BIT[i]+=w;
}
int qry(int x){
	int res=0;
	for (int i=x;i;i-=lowbit(i)) res+=BIT[i];
	return res;
}
namespace A{
	int tot,nxt[maxe],lnk[maxn],son[maxe],f[maxn];
	inline void add(int x,int y){
		son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot,f[y]++;
	}
}
namespace B{
	int tot,nxt[maxe],lnk[maxn],son[maxe],f[maxn];
	inline void add(int x,int y){
		son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot,f[y]++;
	}
}
void dfsA(int x){
	using namespace A;
	in[x]=++tim;
	for (int j=lnk[x];j;j=nxt[j])
	 dfsA(son[j]);
	out[x]=tim;
}
void dfsB(int x){
	using namespace B;
	ist(in[x],1);
	int tem=qry(out[x])-qry(in[x]);
	for (int j=lnk[x];j;j=nxt[j])
	 dfsB(son[j]);
	int t=qry(out[x])-qry(in[x])-tem;
	ans+=(ll)t*(t-1)/2;
}
int main(){
	n=red();
	for (int i=1,x,y;i<n;i++) x=red(),y=red(),A::add(x,y);
	for (int i=1,x,y;i<n;i++) x=red(),y=red(),B::add(x,y);
	for (int i=1;i<=n;i++) if (!A::f[i]) dfsA(i);
	for (int i=1;i<=n;i++) if (!B::f[i]) dfsB(i);
	printf("%lld",ans);
	return 0;
}
