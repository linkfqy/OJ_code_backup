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

const int maxn=10005,maxe=100005;
int n,e,c[maxn],f[maxn],fa[maxn];ll ans;
inline int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
struct edge{
	int x,y,w;
	bool operator<(const edge&b)const {return w<b.w;}
}a[maxe];
void kruskal(){
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=e;i++){
		if (getfa(a[i].x)==getfa(a[i].y)) continue;
		fa[getfa(a[i].x)]=getfa(a[i].y);
		ans+=a[i].w*2;f[a[i].x]++;f[a[i].y]++;
	}
}
int main(){
	n=red(),e=red();int mn=0x3f3f3f3f;
	for (int i=1;i<=n;i++) c[i]=red(),mn=min(mn,c[i]);
	for (int i=1;i<=e;i++) a[i].x=red(),a[i].y=red(),a[i].w=red()*2+c[a[i].x]+c[a[i].y];
	sort(a+1,a+1+e);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=e;i++){
		if (getfa(a[i].x)==getfa(a[i].y)) continue;
		fa[getfa(a[i].x)]=getfa(a[i].y);ans+=a[i].w;
	}
	printf("%lld",ans+mn);
	return 0;
}
