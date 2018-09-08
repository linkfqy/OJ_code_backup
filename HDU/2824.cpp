#include<cstdio>
typedef long long ll;

const int maxn=3000005;
int p[maxn],phi[maxn];
bool vis[maxn];
void makep(int n){
	phi[1]=1;
	for (int i=2;i<=n;i++){
		if (!vis[i]) p[++p[0]]=i,phi[i]=i-1;
		for (int j=1;j<=p[0]&&i*p[j]<=n;j++){
			vis[i*p[j]]=1;
			if (i%p[j]==0) {phi[i*p[j]]=phi[i]*p[j];break;}else phi[i*p[j]]=phi[i]*phi[p[j]];
		}
	}
}
int main(){
	makep(3000000);
	int l,r;
	while (~scanf("%d%d",&l,&r)){
		ll ans=0;
		for (int i=l;i<=r;i++) ans+=phi[i];
		printf("%lld\n",ans);
	}
	return 0;
}
