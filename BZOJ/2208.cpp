#include<cstdio>
#include<bitset>
using namespace std;
const int maxn=2005;
int n,ans;
char s[maxn];
bitset<maxn> f[maxn];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%s",s);
		for (int j=1;j<=n;j++)
		 if (s[j-1]=='1'||i==j) f[i][j]=1;
	}
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=n;j++)
	  if (f[j].test(i)) f[j]|=f[i];
	for (int i=1;i<=n;i++) ans+=f[i].count();
	printf("%d",ans);
	return 0;
}
