#include<cstdio>
int n;
long long ans;
int main(){
	scanf("%d",&n);ans=0;
	for (int i=1;i<=n;i++) ans+=n/i;
	printf("%lld",ans);
	return 0;
}
