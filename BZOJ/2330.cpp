#include<cstdio>
#include<algorithm>
using namespace std;
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

const int maxn=100005,maxe=200005;
int n,q;
int nxt[maxe],son[maxe],lnk[maxn],tot,w[maxe];
inline void add(int x,int y,int z){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=z;
}
int dst[maxn],que[maxn],num[maxn];
bool vis[maxn];
bool spfa(){
	int hed=0,til=n;
	for (int i=1;i<=n;i++) dst[i]=1,que[i]=i,vis[i]=1;
	while (hed!=til){
		int x=que[hed=(hed+1)%maxn];
		vis[x]=0;
		for (int j=lnk[x];j;j=nxt[j])
		 if (dst[son[j]]<dst[x]+w[j]){
		 	dst[son[j]]=dst[x]+w[j];
		 	if (!vis[son[j]]){
		 		vis[son[j]]=1,que[til=(til+1)%maxn]=son[j];
		 		if (++num[son[j]]>n) return 0;
			 }
		 }
	}
	return 1;
}
int main(){
	n=red(),q=red();
	while (q--){
		int c=red(),x=red(),y=red();
		if (c>=4) c-=2,swap(x,y);
		if (c==1) add(x,y,0),add(y,x,0);else
		if (c==2) {if (x==y) return puts("-1"),0;add(x,y,1);}else
		if (c==3) add(y,x,0);
	}
	if (!spfa()) return puts("-1"),0;
	long long ans=0;
	for (int i=1;i<=n;i++) ans+=dst[i];
	printf("%lld",ans);
	return 0;
}
