#include<cstdio>
#include<cmath>
#define LL long long

LL n,nn,m,ans,a[3162300];
int main(){
	scanf("%lld%lld",&m,&n);nn=sqrt(n);
	ans=n*(m);
	for (int k=1;k<=nn;k++){
		a[k]=n/k;
		LL l=n/(k+1)+1,r=n/k;
		if (l>m) continue;
		if (r>m) r=m;
		ans-=(k*((l+r)*(r-l+1)/2));
	}
	for (int i=1;i<nn;i++){
		LL k=a[i],l=n/(k+1)+1,r=n/k;
		if (l>m) continue;
		if (r>m) r=m;
		ans-=(k*((l+r)*(r-l+1)/2));
	}
	if (n/nn!=nn){
		LL k=a[nn],l=n/(k+1)+1,r=n/k;
		ans-=(k*((l+r)*(r-l+1)/2));
	}
	printf("%lld",ans);
	return 0;
}
