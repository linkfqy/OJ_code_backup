#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=100005,N=maxn-5;
int n,q,a[maxn],mu[maxn],p[maxn];
ll f[maxn];
vector<int> fac[maxn];
bool vis[maxn];
void prepare(){
	mu[1]=1;
	for (int i=2;i<=N;i++){
		if (!vis[i]) p[++p[0]]=i,mu[i]=-1;
		for (int j=1;j<=p[0]&&i*p[j]<=N;j++){
			vis[i*p[j]]=1;
			if (i%p[j]==0) {mu[i*p[j]]=0;break;}
			 else mu[i*p[j]]=-mu[i];
		}
	}
	for (int i=1;i<=N;i++)
	 for (int j=1;i*j<=N;j++) fac[i*j].push_back(i);
	for (int i=1;i<=n;i++)
	 for (int j=0;j<fac[i].size();j++)
	  f[fac[i][j]]+=a[i];
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	prepare();
	while (q--){
		int c;scanf("%d",&c);
		if (c==1){
			int i,b;scanf("%d%d",&i,&b);
			for (int j=0;j<fac[i].size();j++)
			 f[fac[i][j]]+=b-a[i];
			a[i]=b;
		}else{
			int i;scanf("%d",&i);ll ans=0;
			for (int j=0;j<fac[i].size();j++)
			 ans+=mu[fac[i][j]]*f[fac[i][j]];
			printf("%lld\n",ans);
		}
	}
	return 0;
}
