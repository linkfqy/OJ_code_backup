#include<cstdio>
typedef long long ll;

const int MOD=1e9+7;
int tst;
int main(){
	scanf("%d",&tst);
	while (tst--){
		int n,k;scanf("%d%d",&n,&k);
		ll ans=0;
		for (int i=1;i<=n;i++){
			ll w=1;
			for (int j=1;j<=k;j++) (w*=i)%=MOD;
			(ans+=w)%=MOD;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
