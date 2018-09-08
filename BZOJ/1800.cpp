#include<cstdio>

const int maxn=25;
int n,S,a[maxn];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		a[i]=a[i-1]+x;S+=x;
	}
	int ans=0;
	for (int i=1;i<=n;i++)
	 for (int j=i+1;j<=n;j++)
	  for (int ii=1;ii<=n;ii++)
	   for (int jj=ii+1;jj<=n;jj++)
	    if (i!=ii&&i!=jj&&j!=ii&&j!=jj)
	    if ((a[j]-a[i])*2==S&&(a[jj]-a[ii])*2==S) ans++;
	printf("%d",ans/2);
	return 0;
}
