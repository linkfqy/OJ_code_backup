#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

const int maxn=10005;
int n,a[maxn];
short f[maxn][maxn];
map<int,int> M;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n); int ans=2;
	for (int i=1;i<=n;i++){
		int tem=0;
		for (int j=i+1;j<=n;j++)
		 if (2*a[i]-a[j]>0&&(tem=M[2*a[i]-a[j]])) f[i][j]=f[tem][i]+1,ans=max(ans,(int)f[i][j]);
		 else f[i][j]=2;
		M[a[i]]=i;
	}
	printf("%d",ans);
	return 0;
}
