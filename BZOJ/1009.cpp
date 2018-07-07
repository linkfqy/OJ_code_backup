#include<cstdio>
#include<cstring>
#define cl(x,y) memset(x,y,sizeof(x))

const int maxm=25;
int n,m,p,fal[maxm];
char s[maxm];
struct matrix{
	int n,m,s[maxm][maxm];
	matrix operator*(const matrix &b){
		matrix c;cl(c.s,0);
		c.n=n;c.m=b.m;
		for (int i=0;i<=c.n;i++)
		 for (int j=0;j<=c.m;j++){
		 	c.s[i][j]=0;
		 	for (int k=0;k<=m;k++)
			 c.s[i][j]+=s[i][k]*b.s[k][j];
			c.s[i][j]%=p;
		 }
		return c;
	}
}A,ans;
matrix power(matrix a,int b){
	matrix w=a,ans;ans.n=a.n;ans.m=a.m;
	cl(ans.s,0);for (int i=0;i<=m;i++) ans.s[i][i]=1;
	while (b){
		if (b&1) ans=ans*w;
		w=w*w;
		b>>=1;
	}
	return ans;
}
int main(){
	scanf("%d%d%d%s",&n,&m,&p,s+1);
	fal[1]=0;
	for (int i=2,j=0;i<=m;i++){
		while (j&&s[j+1]!=s[i]) j=fal[j];
		if (s[j+1]==s[i]) j++;
		fal[i]=j;
	}
	A.n=A.m=m;
	for (int y=0;y<m;y++)
	 for (char i='0';i<='9';i++){
	 	int j=y;
	 	while (j&&s[j+1]!=i) j=fal[j];
	 	if (s[j+1]==i) j++;
	 	if (j<m) A.s[j][y]++;
	 }
	ans.n=m;ans.m=0;ans.s[0][0]=1;
	ans=power(A,n)*ans;
	int res=0;
	for (int i=0;i<m;i++) res=(res+ans.s[i][0])%p;
	printf("%d",res);
	return 0;
}
