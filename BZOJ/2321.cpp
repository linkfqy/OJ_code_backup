#include<cstdio>
typedef long long ll;

int n,m; ll E1=0,E2=0;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++){
	 	int x;scanf("%d",&x);
	 	E1+=x*(i*i+j*j);
	 }
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++){
	 	int x;scanf("%d",&x);
	 	E2+=x*(i*i+j*j);
	 }
	printf("%lld",(E1-E2)/2);
	return 0;
}
