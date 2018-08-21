#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=200005;
int n,N,a[maxn];
int main(){
	scanf("%d",&n);N=2*n;
	for (int i=1;i<=N;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+N);
	ll ans=((ll)a[n]-a[1])*(a[N]-a[n+1]);
	for (int i=2;i<=n;i++)
	 ans=min(ans,((ll)a[N]-a[1])*(a[i+n-1]-a[i]));
	printf("%lld",ans);
	return 0;
}
