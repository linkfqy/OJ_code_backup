#include<cstdio>

int main(){
	int n,x=0,ans=0;
	scanf("%d",&n);if (n<0) n=-n;
	while (x<n||(x-n&1)) x+=(++ans);
	printf("%d",ans);
	return 0;
} 
