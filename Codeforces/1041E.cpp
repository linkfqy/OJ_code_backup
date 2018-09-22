#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=1005;
int n,X[maxn],Y[maxn],dep[maxn],lst[maxn],len;
pair<int,int> ans[maxn];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&X[i],&Y[i]);
		dep[X[i]]++;dep[Y[i]]++;
	}
	if (dep[n]!=n-1) return puts("NO"),0;
	for (int i=1;i<=n;i++)
	 if (dep[i]) lst[i]=n;
	for (int i=1;i<=n;i++)
	 if (dep[i]==0){
	 	int j;
	 	for (j=i+1;j<n;j++)
	 	 if (dep[j]>1) break;
	 	if (j>=n) return puts("NO"),0;
	 	ans[++len]=make_pair(lst[j],i);
	 	dep[j]--;lst[j]=i;
	 	if (!dep[j]) ans[++len]=make_pair(i,n);
	 }
	for (int i=1;i<=n;i++)
	 if (dep[i]==1) ans[++len]=make_pair(lst[i],i);
	puts("YES");
	for (int i=1;i<n;i++) printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}
