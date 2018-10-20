#include<cstdio>
typedef long long ll;

const int maxn=2000005;
int n;
ll c[maxn],ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		c[x]++;
	}
	for (int i=1;i<=2000000;i++){
		ans+=(c[i]-1)*c[i];
		for (int j=2*i;j<=2000000;j+=i)
		 ans+=c[i]*c[j];
	}
	printf("%lld",ans);
	return 0;
}
