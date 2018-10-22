#include<cstdio>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;

const int maxn=30005,maxm=205;
int n,m,s;
ull pw[maxm],hsh[maxn][maxm],a[maxn];
char ch[maxm];

int main(){
	scanf("%d%d%d",&n,&m,&s);
	pw[0]=1;
	for (int i=1;i<=m;i++) pw[i]=pw[i-1]*149;
	for (int i=1;i<=n;i++){
		scanf("%s",ch+1);
		for (int j=1;j<=m;j++)
		 hsh[i][j]=hsh[i][j-1]*149+ch[j];
	}
	int ans=0;
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++) a[j]=hsh[j][i-1]*pw[m-i]+hsh[j][m]-hsh[j][i]*pw[m-i];
		sort(a+1,a+n+1);
		int s=0;a[0]=-1;
		for (int j=1;j<=n;j++)
			if (a[j]!=a[j-1]) ans+=s*(s-1)/2,s=1;
			else s++;
		ans+=s*(s-1)/2;
	}
	printf("%d",ans);
	return 0;
}
