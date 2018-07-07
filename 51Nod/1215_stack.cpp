#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;

const int maxn=50005;
int n,a[maxn],stk[maxn],len;
LL l[maxn];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	len=0;LL ans=0;
	for (int i=1;i<=n;i++){
		while (len&&a[stk[len]]<=a[i]) ans+=l[stk[len]]*(i-stk[len])*a[stk[len]],len--;
		l[i]=i-stk[len];stk[++len]=i;
	}
	while (len) ans+=l[stk[len]]*(n-stk[len]+1)*a[stk[len]],len--;
	for (int i=1;i<=n;i++){
		while (len&&a[stk[len]]>=a[i]) ans-=l[stk[len]]*(i-stk[len])*a[stk[len]],len--;
		l[i]=i-stk[len];stk[++len]=i;
	}
	while (len) ans-=l[stk[len]]*(n-stk[len]+1)*a[stk[len]],len--;
	printf("%lld",ans);
	return 0;
}
