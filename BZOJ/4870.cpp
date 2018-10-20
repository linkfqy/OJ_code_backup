#include<cstdio>
#include<cstring>
#define cl(x,y) memset(x,y,sizeof(x))
typedef long long ll;

int n,p,k,r;
struct matrix{
	int n,m; ll s[50][50];
	matrix () {cl(s,0);n=m=0;}
}t,ans;
inline matrix operator*(const matrix&a,const matrix&b){
	matrix c;
	c.n=a.n;c.m=b.m;
	for (int i=0;i<c.n;i++)
	 for (int j=0;j<c.m;j++)
	  for (int k=0;k<a.m;k++)
	   (c.s[i][j]+=a.s[i][k]*b.s[k][j])%=p;
	return c;
}
matrix power(matrix a,ll b){
	matrix w=a,res;
	res.n=res.m=k; for (int i=0;i<k;i++) res.s[i][i]=1;
	while (b){
		if (b&1) res=res*w;
		w=w*w;
		b>>=1;
	}
	return res;
}
int main(){
	scanf("%d%d%d%d",&n,&p,&k,&r);
	ans.n=k;ans.m=1; ans.s[0][0]=1;
	t.n=t.m=k;
	for (int i=0;i<k;i++) t.s[i][i]++,t.s[i][(i-1+k)%k]++;
	ans=power(t,(ll)n*k)*ans;
	printf("%lld",ans.s[r][0]);
	return 0;
}
