#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=15;
int sum,n,a[maxn],ans[maxn],suc;
void dfs(int stp,int s){
	if (suc) return;
	if (stp>n){
		if (s!=0&&sum-s!=0&&s!=sum-s){
			suc=1;
			printf("%d\n",ans[0]);
			for (int i=1;i<=ans[0];i++) printf("%d ",ans[i]);
		}
		return;
	}
	dfs(stp+1,s);
	ans[++ans[0]]=stp;
	dfs(stp+1,s+a[stp]);
	ans[0]--;
}
int main(){
	scanf("%d",&n); if (n==1) return puts("-1"),0;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
	dfs(1,0);
	if (!suc) puts("-1");
	return 0;
}
