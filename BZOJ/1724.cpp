#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;

int n;
priority_queue<int,vector<int>,greater<int> > Q;
int main(){
	scanf("%d",&n);
	for (int i=1,x;i<=n;i++) scanf("%d",&x),Q.push(x);
	ll ans=0;
	while (Q.size()>1){
		int x=Q.top();Q.pop();
		int y=Q.top();Q.pop();
		ans+=x+y;
		Q.push(x+y);
	}
	printf("%lld",ans);
	return 0;
}
