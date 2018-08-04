#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=50005;
int n,m,d,l,a[maxn];
int main(){
	scanf("%d%d%d%d",&n,&m,&d,&l);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);int ans=0;
	for (int i=1;i<=n;i++){
		if (a[i]-(ans/m)*d>=l) ans++;
	}
	printf("%d",ans);
	return 0;
}
