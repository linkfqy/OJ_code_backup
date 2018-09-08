#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=1000005;
int n,q,a[maxn],f[maxn],ans;
vector<int> V[maxn];
void merge(int x,int y){
	if (V[f[x]].size()>V[f[y]].size()) swap(f[x],f[y]);
	int fx=f[x],fy=f[y];
	if (fx==fy) return;
	for (int i=0;i<V[fx].size();i++)
	 ans-=(a[V[fx][i]+1]==fy)+(a[V[fx][i]-1]==fy);
	for (int i=0;i<V[fx].size();i++)
	 a[V[fx][i]]=fy,V[fy].push_back(V[fx][i]);
	V[fx].clear();
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=1e6;i++) f[i]=i;
	for (int i=1;i<=n;i++)
	 scanf("%d",&a[i]),ans+=(a[i]!=a[i-1]),V[a[i]].push_back(i);
	while (q--){
		int x,y;scanf("%d",&x);
		if (x==1) scanf("%d%d",&x,&y),merge(x,y);else printf("%d\n",ans);
	}
	return 0;
}
