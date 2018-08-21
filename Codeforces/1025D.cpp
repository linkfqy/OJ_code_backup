#include<cstdio>
#include<cstring>

const int maxn=705;
int n,a[maxn],f[maxn][maxn][2];
bool cst[maxn][maxn];
int gcd(int x,int y) {return !y?x:gcd(y,x%y);}
bool dfs(int l,int r,int d){
	if (l>r) return 1;
	if (f[l][r][d]>=0) return f[l][r][d];
	int fa=(d?r+1:l-1);
	for (int i=l;i<=r;i++)
	 if (cst[fa][i]&&dfs(l,i-1,1)&&dfs(i+1,r,0)) return f[l][r][d]=1;
	return f[l][r][d]=0;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),cst[i][0]=cst[0][i]=1;
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=n;j++) cst[i][j]=(gcd(a[i],a[j])>1);
	memset(f,-1,sizeof(f));
	if (dfs(1,n,0)) puts("Yes");else puts("No");
	return 0;
}
