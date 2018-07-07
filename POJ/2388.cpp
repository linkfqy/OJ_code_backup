#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=10005;
int n,a[maxn];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	printf("%d",a[n+1>>1]);
	return 0;
}
