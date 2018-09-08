#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=100005;
int n,e,lst[maxn],nxt[maxn];
vector<int> V[maxn];
void dfs(int x){
	printf("%d\n",x);
	int l=lst[x],r=nxt[x];
	nxt[l]=r;lst[r]=l;
	for (int i=nxt[0];i<=n;i=nxt[i]){
		vector<int>::iterator it=lower_bound(V[x].begin(),V[x].end(),i);
		if (it==V[x].end()||*it!=i) return (void)dfs(i);
	}
}
int main(){
	scanf("%d%d",&n,&e);
	for (int i=1,x,y;i<=e;i++) scanf("%d%d",&x,&y),V[x].push_back(y),V[y].push_back(x);
	for (int i=1;i<=n;i++)
	 sort(V[i].begin(),V[i].end()),lst[i]=i-1,nxt[i]=i+1;
	nxt[n+1]=n+1;lst[0]=0;
	dfs(1);
	return 0;
}
