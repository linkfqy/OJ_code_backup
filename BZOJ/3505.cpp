#include<cstdio>
typedef long long ll;

int n,m,nm;
ll ans;
ll gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
int main(){
	scanf("%d%d",&n,&m);nm=(n+1)*(m+1);
	ans=(ll)nm*(nm-1)*(nm-2)/6;
	for (int i=0;i<=n;i++)
	 for (int j=0;j<=m;j++)
	  if (i||j){
	  	ll s=(gcd(i,j)-1)*(n-i+1)*(m-j+1);
	  	ans-=s*((i&&j)?2:1);
	  }
	printf("%lld",ans);
	return 0;
}
