#include <cstdio>
typedef long long ll;

using namespace std;
const int a[12]={0,4,10,20,35,56,83,116,155,198,244,292};
int n;ll ans;
int main(){
	scanf("%d",&n);
	if (n<=11) ans=a[n];
	 else ans=a[11]+((ll)n-11)*49;
	printf("%lld", ans);
	return 0;
}
