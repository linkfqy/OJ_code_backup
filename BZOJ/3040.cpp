#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
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

const int maxn=1000005,maxe=10000005;
int n,e,T,rxa,rxc,rya,ryc,rp;
int tot,nxt[maxe],son[maxe],lnk[maxn],w[maxe];
inline void add(int x,int y,int z){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=z;
}
ll dst[maxn]; bool vis[maxn];
struct data{
	ll d;int id;
	data () {}
	data (int _id,ll _d):id(_id),d(_d) {}
	bool operator<(const data&b)const {return d>b.d;}
};
priority_queue<data> H;
void DIJ(){
	cl(dst,63);
	dst[1]=0;H.push(data(1,0));
	while (!H.empty()){
		data k=H.top();H.pop(); if (vis[k.id]) continue;
		vis[k.id]=1;if (k.id==n) return;
		for (int j=lnk[k.id];j;j=nxt[j])
		 if (!vis[son[j]]&&dst[son[j]]>dst[k.id]+w[j])
		  dst[son[j]]=dst[k.id]+w[j],H.push(data(son[j],dst[son[j]]));
	}
}
int main(){
	n=red(),e=red();
	T=red();rxa=red(),rxc=red(),rya=red(),ryc=red();rp=red();
	for (int i=1,x=0,y=0,z=0;i<=T;i++){
		x=(x*rxa+rxc)%rp; y=(y*rya+ryc)%rp;
		int a=min(x%n+1,y%n+1),b=max(y%n+1,y%n+1);
		add(a,b,1e8-100*a);
	}
	for (int i=T+1,x,y,z;i<=e;i++) x=red(),y=red(),z=red(),add(x,y,z);
	DIJ();
	printf("%lld",dst[n]);
	return 0;
}
