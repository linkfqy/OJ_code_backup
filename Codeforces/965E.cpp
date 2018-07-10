#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn=100005;
int n,dep[maxn];
int rot,len,son[maxn][26],fa[maxn];
char s[maxn];
bool vis[maxn];
priority_queue<int> S[maxn];
void add_s(char *s){
	int x=rot;
	for (int i=0;s[i];i++){
		int c=s[i]-'a';
		if (!son[x][c]) son[x][c]=++len,fa[len]=x;
		x=son[x][c];
	}
	vis[x]=1;
}
int dfs(int x){
	dep[x]=dep[fa[x]]+1;
	int res=0;if (vis[x]) S[x].push(dep[x]),res+=dep[x];
	for (int i=0,s=son[x][i];i<26;i++,s=son[x][i])
		if (s){
			res+=dfs(s);
			while (!S[s].empty()) S[x].push(S[s].top()),S[s].pop();	   
		}
	if (!vis[x]&&x!=rot)
		res-=S[x].top(),S[x].pop(),
		res+=dep[x],S[x].push(dep[x]);
	return res;
}
int main(){
	scanf("%d",&n); rot=len=1;
	for (int i=1;i<=n;i++) scanf("%s",s),add_s(s);
	dep[0]=-1;
	printf("%d",dfs(rot));
	return 0;
}
