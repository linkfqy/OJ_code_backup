#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=105;
int n,d,a[maxn];
int main(){
	scanf("%d%d",&n,&d);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int ans=2;
	for (int i=2;i<=n;i++)
	 if (a[i]-a[i-1]==2*d) ans++;else
	 if (a[i]-a[i-1]>2*d) ans+=2;
	printf("%d",ans);
	return 0;
} 
