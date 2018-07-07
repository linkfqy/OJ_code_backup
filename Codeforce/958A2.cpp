#include<cstdio>

const int maxn=2005;
typedef unsigned long long  ull;
int n,m;
char a[maxn][maxn],b[maxn][maxn];
ull hsha[maxn],hshb[maxn][maxn];
ull hash(char *s){
	ull res=0;
	for (int i=0;i<m;i++) res=res*29+s[i]-'a'+1;
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%s",a[i]+1);
	for (int i=1;i<=m;i++) scanf("%s",b[i]+1);
	for (int i=1;i<=n;i++) hsha[i]=hash(a[i]+1);
	for (int i=1;i<=m;i++)
	 for (int j=1;j<=n-m+1;j++) hshb[i][j]=hash(b[i]+j);
	for (int i=1;i<=n-m+1;i++)
	 for (int j=1;j<=n-m+1;j++){
	 	bool suc=1;
	 	for (int k=0;k<m;k++)
	 	 if (hsha[i+k]!=hshb[1+k][j]) {suc=0;break;}
	 	if (suc) return printf("%d %d",i,j),0;
	 }
	return 0;
}
