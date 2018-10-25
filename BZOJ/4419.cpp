#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;

const int maxn=200005;
int n,q,num[maxn],ans[maxn];
set<int> S[maxn];
int main(){
	scanf("%d%d",&n,&q);
	while (q--){
		char c=getchar();while (c!='+'&&c!='-'&&c!='!') c=getchar();
		if (c=='!'){
			int x;scanf("%d",&x);
			num[x]++;
		}else
		if (c=='+'){
			int x,y;scanf("%d%d",&x,&y);
			S[x].insert(y); S[y].insert(x);
			ans[x]-=num[y]; ans[y]-=num[x];
		}else{
			int x,y;scanf("%d%d",&x,&y);
			S[x].erase(y); S[y].erase(x);
			ans[x]+=num[y]; ans[y]+=num[x];
		}
	}
	for (int i=1;i<=n;i++)
	 for (set<int>::iterator it=S[i].begin();it!=S[i].end();it++)
	  ans[i]+=num[*it];
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}
