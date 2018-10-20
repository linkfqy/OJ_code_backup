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

const int maxn=100005,maxe=100005;
int n,M; ll ans,l[maxn];
int son[maxe],nxt[maxe],lnk[maxn],tot;
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
int key[maxn],ls[maxn],rs[maxn],siz[maxn],rt[maxn]; ll sum[maxn];
inline void pushup(int x) {siz[x]=siz[ls[x]]+siz[rs[x]]+1;sum[x]=sum[ls[x]]+sum[rs[x]]+key[x];}
int merge(int a,int b){
	if (!a||!b) return a+b;
	if (key[a]<key[b]) swap(a,b);
	if (rand()&1) ls[a]=merge(ls[a],b);else rs[a]=merge(rs[a],b);
	pushup(a);
	return a;
}
int del(int a){
	if (!a) return 0;
	return merge(ls[a],rs[a]);
}
void dfs(int x){
	for (int j=lnk[x];j;j=nxt[j]){
		dfs(son[j]);
		rt[x]=merge(rt[x],rt[son[j]]);
	}
	while (sum[rt[x]]>M) rt[x]=del(rt[x]);
	ans=max(ans,l[x]*siz[rt[x]]);
}
int main(){
	n=red(),M=red();
	for (int i=1;i<=n;i++){
		int x=red();add(x,i);
		sum[i]=key[i]=red(),l[i]=red();
		rt[i]=i;siz[i]=1;
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
