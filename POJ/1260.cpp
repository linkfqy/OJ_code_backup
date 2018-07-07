#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=105;
int tst,n,a[maxn],p[maxn],f[maxn];
int main(){
	scanf("%d",&tst);
	while (tst--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d%d",&a[i],&p[i]);
		memset(f,63,sizeof(f));
		f[0]=0;
		for (int i=1;i<=n;i++){
			int s=10;
			for (int j=i;j>=1;j--)
			 s+=a[j],f[i]=min(f[i],f[j-1]+s*p[i]);
		}
		printf("%d\n",f[n]);
	}
	return 0;
}
