#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,a[15],b[15],x;
int main(){
	scanf("%d%d",&n,&m);
	int ai=10,bi=10;x=10;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),ai=min(ai,a[i]);
	for (int i=1;i<=m;i++) scanf("%d",&b[i]),bi=min(bi,b[i]);
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	  if (a[i]==b[j]) x=min(x,a[i]);
	if (x<10) return printf("%d",x),0;
	if (ai>bi) swap(ai,bi);
	printf("%d",ai*10+bi);
	return 0;
}
