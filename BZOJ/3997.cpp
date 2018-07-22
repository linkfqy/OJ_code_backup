#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
inline char nc(){
	static char buf[100000],*l=buf,*r=buf;
	return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++;
}
inline int red(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
	return res*f;
}

const int maxn=1005;
int tst,n,m,a[maxn][maxn];
ll f[maxn][maxn];
int main(){
	tst=red();
	while (tst--){
		n=red(),m=red();
		for (int i=1;i<=n;i++)
		 for (int j=1;j<=m;j++) a[i][j]=red();
		for (int i=1;i<=n;i++)
		 for (int j=m;j>=1;j--)
		  f[i][j]=max(max(f[i-1][j],f[i][j+1]),f[i-1][j+1]+a[i][j]);
		printf("%lld\n",f[n][1]);
	}
	return 0;
}
