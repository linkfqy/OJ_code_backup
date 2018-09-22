#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;

const int maxn=10005;
int n,K,w[30],sum,ans;
multiset<int> S;
typedef set<int>::iterator iter;
int main(){
	scanf("%d%d",&n,&K);
	for (int i=1;i<=K;i++) scanf("%d",&w[i]),S.insert(w[i]),sum+=w[i];
	ans=0x7fffffff;
	while (1){
		if (S.size()>=n){
			if (sum>=ans) break;else ans=sum;
		}
		int x=*S.begin();S.erase(S.begin());sum-=x;
		for (int i=1;i<=K;i++)
		 S.insert(x+w[i]),sum+=x+w[i];
		while (S.size()>n) sum-=*(--S.end()),S.erase(--S.end());
	}
	printf("%d",ans);
	return 0;
}