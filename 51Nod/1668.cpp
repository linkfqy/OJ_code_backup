#include<cstdio>
#include<cstring>
#define cl(x,y) memset(x,y,sizeof(x))
typedef long long ll;

const ll tt=1e9+7;
ll n;
struct matrix{
	ll s[9][9];
	void E() {cl(s,0);for (int i=1;i<=4;i++) s[i][i]=1;}
}A,ans;
matrix operator*(const matrix&a,const matrix&b){
	matrix c;cl(c.s,0);
	for (int i=1;i<=4;i++)
	 for (int j=1;j<=4;j++)
	  for (int k=1;k<=4;k++)
	   (c.s[i][j]+=a.s[i][k]*b.s[k][j]%tt)%=tt;
	return c;
}
matrix power(matrix a,ll b){
	matrix w,res;res.E();w=a;
	while (b){
		if (b&1) res=res*w;
		w=w*w;
		b>>=1;
	}
	return res;
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%lld",&n); if (n==1) return printf("2"),0;
	A.s[1][1]=A.s[2][1]=A.s[4][2]=A.s[1][3]=A.s[2][3]=A.s[3][4]=A.s[4][4]=1;
	ans.s[1][1]=ans.s[1][2]=ans.s[1][3]=ans.s[1][4]=1;
	ans=ans*power(A,n-2);
	printf("%lld",(ans.s[1][1]+ans.s[1][2]+ans.s[1][3]+ans.s[1][4])%tt);
	return 0;
}
