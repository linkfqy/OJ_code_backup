#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=200005;
int n,a[maxn],ans=0;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++){
		for (int l=a[i],r=2*l-1;l<=a[n];l=r+1,r+=a[i])
		 ans=max(ans,*(lower_bound(a+i,a+n+1,r+1)-1)%a[i]);
	}
	printf("%d",ans);
	return 0;
}
