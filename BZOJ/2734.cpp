#include<cstdio>
#include<cstring>
#define cl(x,y) memset(x,y,sizeof(x))
typedef long long ll;

const int MOD=1e9+1,maxn=20,maxm=13,maxs=1<<13;
int n,e,N,M;
ll f[maxn][maxs],pw2[maxn],pw3[maxn],ans;
void maker(){
	N=M=1;pw2[0]=pw3[0]=1;
	for (int i=1;pw2[i-1]*2<=n;i++) pw2[i]=pw2[i-1]*2,N++;
	for (int i=1;pw3[i-1]*3<=n;i++) pw3[i]=pw3[i-1]*3,M++;
}
int highbit(int j) {for (int t=M;t;t--) if (j&(1<<t-1)) return t;return 0;}
ll DP(int x){
	N=M=1;
	for (int i=x;i*2<=n;i*=2) N++;
	for (int i=x;i*3<=n;i*=3) M++;
	for (int i=1;i<=N;i++)
	 for (int j=0;j<(1<<M);j++) f[i][j]=0;
	f[0][0]=1;
	for (int i=1;i<=N;i++)
	 for (int j=0;j<(1<<M);j++){
	 	if (j&(j>>1)) continue;ll w=pw2[i-1]*pw3[highbit(j)-1]*(j!=0);
	 	if (w>n||x*w>n) break;
	 	for (int k=0;k<(1<<M);k++)
	 	 if (!(k&j)) (f[i][j]+=f[i-1][k])%=MOD;
	 }
	ll res=0;
	for (int j=0;j<(1<<M);j++) (res+=f[N][j])%=MOD;
	return res;
}
int main(){
	scanf("%d",&n);
	maker(); ans=1;
	for (int i=1;i<=n;i++)
	 if (i%2!=0&&i%3!=0) (ans*=DP(i))%=MOD;
	printf("%lld",ans);
	return 0;
}
