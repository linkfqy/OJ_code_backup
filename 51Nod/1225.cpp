#include<cstdio>
#include<cmath>
#define LL long long

const int tt=1000000007,inv2=tt+1>>1;
LL n,nn,m,ans,a[3162300];
int main(){
	scanf("%lld",&n);nn=sqrt(n);m=n; 
	ans=n%tt*(m%tt)%tt;
	for (int k=1;k<=nn;k++){
		a[k]=n/k;
		LL l=n/(k+1)+1,r=n/k;
		if (l>m) continue;
		if (r>m) r=m;
		ans=(ans-(k%tt*((l+r)%tt)%tt*((r-l+1)%tt)%tt*inv2%tt)+tt)%tt;
	}
	for (int i=1;i<nn;i++){
		LL k=a[i],l=n/(k+1)+1,r=n/k;
		if (l>m) continue;
		if (r>m) r=m;
		ans=(ans-(k%tt*((l+r)%tt)%tt*((r-l+1)%tt)%tt*inv2%tt)+tt)%tt;
	}
	if (n/nn!=nn){
		LL k=a[nn],l=n/(k+1)+1,r=n/k;
		ans=(ans-(k%tt*((l+r)%tt)%tt*((r-l+1)%tt)%tt*inv2%tt)+tt)%tt;
	}
	printf("%lld",ans);
	return 0;
}
