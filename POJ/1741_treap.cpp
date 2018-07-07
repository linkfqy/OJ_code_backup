#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=10005,maxe=20005;
int n,K,ans;
int son[maxe],nxt[maxe],lnk[maxn],w[maxe],tot;
bool vis[maxn];
void add(int x,int y,int wi){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=wi;
}
inline int red(){
	int tot=0;char ch=getchar();
	while (ch<'0'||'9'<ch) ch=getchar();
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot;
}
struct node{
	node* s[2];
	int size,k,cnt,f;
	void maintain() {size=s[0]->size+s[1]->size+cnt;}
}treap[132880],nil;
typedef node* P_node;
P_node null,len,rt[maxn];
void clear(){
	null=&nil;
	null->s[0]=null->s[1]=null;
	null->size=null->cnt=0;
	len=treap;
}
P_node newnode(int key,int num){
	len->k=key;len->s[0]=len->s[1]=null;
	len->cnt=len->size=num;len->f=rand();
	return len++;
}
void rot(P_node &x,int d){
	P_node k=x->s[d^1];x->s[d^1]=k->s[d];k->s[d]=x;
	x->maintain();k->maintain();x=k;
}
void ist(P_node &x,int key,int num){
	if (x==null) x=newnode(key,num);else
	if (key==x->k) x->cnt+=num;else{
		int d=key>x->k;
		ist(x->s[d],key,num);if (x->s[d]->f > x->f) rot(x,d^1);
	}
	x->maintain();
}
void merge(P_node &a,P_node b){
	if (b==null) return;
	ist(a,b->k,b->cnt);
	merge(a,b->s[0]);merge(a,b->s[1]);
}
int Rank(P_node x,int key){
	if (x==null) return 0;
	if (key==x->k) return x->s[0]->size+x->cnt;
	if (key<x->k) return Rank(x->s[0],key);
	return Rank(x->s[1],key)+x->s[0]->size+x->cnt;
}
int asksum(P_node a,P_node b,int x){
	if (b==null) return 0;
	return b->cnt*Rank(a,x-b->k)+asksum(a,b->s[0],x)+asksum(a,b->s[1],x);
}
void dfs(int x,int dst){
	vis[x]=1;
	for (int j=lnk[x];j;j=nxt[j])
	 if (!vis[son[j]]){
	 	dfs(son[j],dst+w[j]);
		if (rt[son[j]]->size > rt[x]->size) swap(rt[son[j]],rt[x]);
	 	ans+=asksum(rt[x],rt[son[j]],2*dst+K);merge(rt[x],rt[son[j]]);
	 }
	ans+=Rank(rt[x],dst+K);
	ist(rt[x],dst,1);
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	n=red(),K=red();
	while (n){
		memset(lnk,0,sizeof(lnk));tot=0;
		clear();for (int i=1;i<=n;i++) rt[i]=null;
		for (int i=1,x,y,wi;i<n;i++) x=red(),y=red(),wi=red(),add(x,y,wi),add(y,x,wi);
		memset(vis,0,sizeof(vis));ans=0;
		dfs(1,0);
		printf("%d\n",ans);
		n=red(),K=red();
	}
}









/*
非常直接的想法……
对于每个节点，用Treap记录该子树每个节点到根(1)的距离
那么如何统计答案？
对于兄弟子树，他们之中的任意节点间都可统计方案数，而且不会重复
其实统计方案数就是询问某Treap中key比x小的个数
统计两棵Treap之间的方案数就是把其中一棵树拆成一个一个点，不断询问
统计之后，将兄弟子树合并，得到了父亲子树的Treap
最后统计一棵子树的根到每个点是否能对答案做出贡献，并插入根节点 
这里就要讲一下启发式合并，在合并过程中，如果我们每次都把较小的Treap拆成一个个点并插入另一个Treap中
就可以保证每个点最多被插入logN次，那么复杂度就是Nlog^2N（注意空间也要开NlogN） 
*/
