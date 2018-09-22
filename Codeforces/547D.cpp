#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=200005,maxe=800005;
int n;
int son[maxe],nxt[maxe],lnk[maxn],tot;
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
struct data{
	int x,y;
}a[maxn];
vector<int> X[maxn],Y[maxn];
bool vis[maxn],s[maxn];
void dfs(int x){
	vis[x]=1;
	for (int j=lnk[x];j;j=nxt[j])
	 if (!vis[son[j]])
	  s[son[j]]=s[x]^1,dfs(son[j]);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y),X[a[i].x].push_back(i),Y[a[i].y].push_back(i);
	for (int i=1;i<=2e5;i++){
		for (int j=0;j<X[i].size();j++)
		 if ((j^1)<X[i].size()) add(X[i][j^1],X[i][j]);
		for (int j=0;j<Y[i].size();j++)
		 if ((j^1)<Y[i].size()) add(Y[i][j^1],Y[i][j]);
	}
	for (int i=1;i<=n;i++) if (!vis[i]) dfs(i);
	for (int i=1;i<=n;i++) putchar(s[i]?'r':'b');
	return 0;
}
