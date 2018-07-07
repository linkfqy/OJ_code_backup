#include<cstdio>
const int maxn=15;
int n,a[maxn],f[maxn][30],s[maxn][30];
void reads(){
	char ch=getchar();
	while ('a'<=ch&&ch<='z') a[++n]=ch-'a'+1,ch=getchar();
}
void DP(){
	for (int i=1;i<=26;i++)
	 f[1][i]=1,s[1][i]=s[1][i-1]+1;
	for (int i=2;i<=n;i++){
		s[i][0]=s[i-1][26];
		for (int j=1;j<=26;j++)
		 f[i][j]=s[i-1][26]-s[i-1][j],
		 s[i][j]=s[i][j-1]+f[i][j];
	}
}
int main(){
	reads();
	for (int i=1;i<n;i++)
	 if (a[i]>=a[i+1]){printf("0");return 0;}
	DP();
	int ans=1+s[n][a[1]-1];
	for (int i=2;i<=n;i++) ans+=s[n-i+1][a[i]-1]-s[n-i+1][a[i-1]];
	printf("%d",ans);
	return 0;
}
