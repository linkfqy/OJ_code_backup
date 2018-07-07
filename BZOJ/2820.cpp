#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=10000005;
int tst,n,m,p[maxn],mu[maxn],t[maxn];
ll sum[maxn];
bool vis[maxn];
void get_mu(){
	int n=10000000;mu[1]=1;
	for (int i=2;i<=n;i++){
		if (!vis[i]) p[++p[0]]=i,mu[i]=-1;
		for (int j=1;j<=p[j]&&i*p[j]<=n;j++){
			vis[i*p[j]]=1;
			if (i%p[j]==0) {mu[i*p[j]]=0;break;}
			 else mu[i*p[j]]=-mu[i];
		}
	}
	for (int i=1;i<=p[0];i++)
	 for (int j=1;p[i]*j<=n;j++) t[p[i]*j]+=mu[j];
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+t[i];
}
ll get(int n,int m){
	if (n>m) swap(n,m);
	ll res=0;
	for (int T=1,lst=0;T<=n;T=lst+1){
		lst=min(n/(n/T),m/(m/T));
		res+=(sum[lst]-sum[T-1])*(n/T)*(m/T);
	}
	return res;
}
int main(){
	scanf("%d",&tst);get_mu();
	while (tst--){
		scanf("%d%d",&n,&m);
		printf("%lld\n",get(n,m));
	}
	return 0;
}
