#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=5005;
int n,R,s[maxn][maxn];
short int a[maxn][maxn];
int main(){
	scanf("%d%d",&n,&R);
	for (int i=1,x,y,z;i<=n;i++) scanf("%d%d%d",&x,&y,&z),a[x+1][y+1]+=z;
	for (int i=1;i<=5001;i++)
	 for (int j=1;j<=5001;j++) s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
	int ans=0;
	for (int i=R;i<=5001;i++)
	 for (int j=R;j<=5001;j++) ans=max(ans,s[i][j]-s[i-R][j]-s[i][j-R]+s[i-R][j-R]);
	printf("%d",ans);
	return 0;
}
