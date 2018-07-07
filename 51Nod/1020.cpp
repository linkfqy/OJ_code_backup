#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=1005,maxm=20005,tt=1000000007;
int n,m,f[maxn][maxm],s[maxm];
int main(){
	n=1000;m=20000;
	f[1][0]=1;
	for (int i=2;i<=n;i++){
//		for (int j=0;j<=m;j++)
//		 for (int k=max(0,j-i+1);k<=j;k++) (f[i][j]+=f[i-1][k])%=tt;
		int s=0,lst=0;
		for (int j=0;j<=m;j++){
			if (lst<j-i+1) s=(s-f[i-1][lst++]+tt)%tt;
			s=(s+f[i-1][j])%tt;
			(f[i][j]+=s)%=tt;
		}
	}
	int tst;
	scanf("%d",&tst);
	while (tst--){
		scanf("%d%d",&n,&m);
		printf("%d\n",f[n][m]);
	}
	return 0;
}
