#include<cstdio>
#include<cmath>
typedef long long ll;

const int maxn=100000;
int m=maxn-5,mu[maxn],p[maxn];
bool vis[maxn];
ll tst,L,R,K,ans;
void get_mu(){
	mu[1]=1;
	for (int i=2;i<=m;i++){
		if (!vis[i]) p[++p[0]]=i,mu[i]=-1;
		for (int j=1;j<=p[0]&&i*p[j]<=m;j++){
			vis[i*p[j]]=1;
			if (i%p[j]==0){mu[i*p[j]]=0;break;}
			 else mu[i*p[j]]=-mu[i];
		}
	}
}
bool check(ll mid){
	ll sm=sqrt(mid),res=0;
	for (ll i=1;i<=sm;i++) res+=mu[i]*(mid/(i*i));
	return res>=K;
}
int main(){
	scanf("%lld",&tst);
	get_mu();
	while (tst--){
		scanf("%lld",&K);
		ans=0;L=1,R=1e10;
		while (L<=R){
			ll mid=L+R>>1;
			if (check(mid)) R=mid-1,ans=mid;else L=mid+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
