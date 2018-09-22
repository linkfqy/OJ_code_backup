#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=1005;
int n,a[maxn],ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for (int i=1;i<n;i++) ans+=a[i+1]-a[i]-1;
	printf("%d",ans);
	return 0;
}
