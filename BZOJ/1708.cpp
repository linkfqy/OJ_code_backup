#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

int n,V,w[30];
ll f[10005];
int main(){
	scanf("%d%d",&n,&V);
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	f[0]=1;
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=V;j++)
	  if (w[i]<=j) f[j]+=f[j-w[i]];
	printf("%lld",f[V]);
	return 0;
}
