#include<cstdio>
#include<string>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=8005,maxe=50005;
int n,e,N;
int tot,son[maxe],nxt[maxe],lnk[maxn];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
map<string,int> id;
int dfn[maxn],low[maxn],stk[maxn],SCC[maxn],times;
bool instk[maxn];
void Tarjan(int x){
	dfn[x]=low[x]=++times;instk[stk[++stk[0]]=x]=1;
	for (int j=lnk[x];j;j=nxt[j])
	 if (!dfn[son[j]]){
	 	Tarjan(son[j]);
		low[x]=min(low[x],low[son[j]]);
	 }else if (instk[son[j]]) low[x]=min(low[x],dfn[son[j]]);
	if (dfn[x]==low[x]){
		SCC[0]++;
		while (stk[stk[0]]!=x) instk[stk[stk[0]]]=0,SCC[stk[stk[0]--]]=SCC[0];
		instk[stk[stk[0]]]=0,SCC[stk[stk[0]--]]=SCC[0];
	}
}
int main(){
	scanf("%d",&n);N=0;
	for (int i=1;i<=n;i++){
		string a,b;cin>>a>>b;
		id[a]=++N; id[b]=++N;
		add(id[b],id[a]);
	}
	scanf("%d",&e);
	for (int i=1;i<=e;i++){
		string a,b;cin>>a>>b;
		add(id[a],id[b]);
	}
	for (int i=1;i<=N;i++)
	 if (!dfn[i]) Tarjan(i);
	for (int i=1;i<=n;i++)
	 if (SCC[i*2-1]==SCC[i*2]) puts("Unsafe");else puts("Safe");
	return 0;
}
