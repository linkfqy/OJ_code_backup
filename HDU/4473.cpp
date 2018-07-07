#include<cstdio>
#define LL long long

LL n;
int main(){
	int i=0;
	while (~scanf("%lld",&n)){
		LL ans=0;
		for (LL i=1;i*i*i<=n;i++)
		 for (LL j=i;j*j*i<=n;j++){
		 	LL num=n/(i*j)-j+1;
		 	if (i==j) ans+=num*3-2;else
		 	 ans+=num*6-3;
		 }
		printf("Case %d: %lld\n",++i,ans);
	}
	return 0;
}
