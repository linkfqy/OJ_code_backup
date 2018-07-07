#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5005;
int n,f[2][maxn];
char a[maxn],b[maxn];
int main(){
	scanf("%d%*c",&n);
	for (int i=1;i<=n;i++) a[i]=b[n-i+1]=getchar();
	f[0][0]=0;
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=n;j++){
	 	f[i&1][j]=max(f[1-i&1][j],f[i&1][j-1]);
	 	if (a[i]==b[j]) f[i&1][j]=max(f[i&1][j],f[1-i&1][j-1]+1);
	 }
	printf("%d",n-f[n&1][n]);
	return 0;
}
