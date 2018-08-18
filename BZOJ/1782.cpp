#include<cstdio>

const int maxn=100005,maxe=200005;
int n,in[maxn],out[maxn],times;
int son[maxe],nxt[maxe],lnk[maxn],tot;
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
int BIT[maxn];
inline void ist(int x,int w){
	for (int i=x;i<=n;i+=(i&-i)) BIT[i]+=w;
}
inline int ask(int x){
	int res=0;
	for (int i=x;i;i-=(i&-i)) res+=BIT[i];
	return res;
}
void dfs(int x,int fa){
	in[x]=++times;
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa) dfs(son[j],x);
	out[x]=times;
}
int main(){
	scanf("%d",&n);
	for (int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	dfs(1,1);
	for (int i=1;i<=n;i++){
		int p;scanf("%d",&p);
		printf("%d\n",ask(in[p]));
		ist(in[p],1);ist(out[p]+1,-1);
	}
	return 0;
}
