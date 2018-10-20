#include<cstdio>
#include<cmath>

int n,m;
int main(){
	scanf("%d%d",&m,&n);
	double ans=0;
	for (int i=1;i<=m;i++) ans+=i*(pow(1.0*i/m,n)-pow(1.0*(i-1)/m,n));
	printf("%.08f",ans);
	return 0;
}
