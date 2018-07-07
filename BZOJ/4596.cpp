#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef long long ll;

const int maxn=25;
typedef ll matrix[maxn][maxn];
const ll MD=1e9+7;
int n,m[maxn];
ll ans;
matrix kir;
struct data{
	int x,y;
	inline void read() {scanf("%d%d",&x,&y);}
}a[maxn][105];
inline void A(ll &a,ll b){ (a+=(b%MD+MD)%MD)%=MD; }
inline ll inv(ll a){
	ll res=1,w=a%MD,b=MD-2;
	while (b){
		if (b&1) res=res*w%MD;
		w=w*w%MD;
		b>>=1;
	}
	return res;
}
ll det(matrix a,int n){
	int tot=0;
	for (int i=1;i<=n;i++){
		int where=-1;
		for (int j=i;j<=n;j++) if (a[j][i]!=0) {where=j;break;}
		if (where<0) return 0;
		if (where>i){
			tot++;
			for (int j=1;j<=n;j++) swap(a[i][j],a[where][j]);
		}
		for (int j=i+1;j<=n;j++){
			ll t=a[j][i]*inv(a[i][i])%MD;
			for (int k=i;k<=n;k++) A(a[j][k],-a[i][k]*t);
		}
	}
	ll res=1;
	for (int i=1;i<=n;i++) (res*=a[i][i])%=MD;
	return (tot&1)?MD-res:res;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		scanf("%d",&m[i]);
		for (int j=1;j<=m[i];j++) a[i][j].read();
	}
	for (int s=0;s<(1<<n-1);s++){
		cl(kir,0);int tot=0;
		for (int i=1;i<=n;i++)
		 if (s&(1<<i-1)){tot++;
		  for (int j=1;j<=m[i];j++){
		  	int x=a[i][j].x,y=a[i][j].y;
		  	A(kir[x][y],-1);A(kir[y][x],-1);A(kir[x][x],1);A(kir[y][y],1);
		  }}
		A(ans,((n-1-tot&1)?-1:1)*det(kir,n-1));
	}
	printf("%lld",ans);
	return 0;
}
