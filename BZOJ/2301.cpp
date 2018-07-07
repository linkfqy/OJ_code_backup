#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=50005;
int tst,a,b,c,d,K,p[maxn],mu[maxn],sum[maxn];
bool vis[maxn];
void get_mu(){
	int n=50000;mu[1]=1;
	for (int i=2;i<=n;i++){
		if (!vis[i]) p[++p[0]]=i,mu[i]=-1;
		for (int j=1;j<=p[j]&&i*p[j]<=n;j++){
			vis[i*p[j]]=1;
			if (i%p[j]==0) {mu[i*p[j]]=0;break;}
			 else mu[i*p[j]]=-mu[i];
		}
	}
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+mu[i];
}
int get(int n,int m){
	n/=K;m/=K;
	if (n>m) swap(n,m);
	int res=0;
	for (int d=1,lst=0;d<=n;d=lst+1){
		lst=min(n/(n/d),m/(m/d));
		res+=(n/d)*(m/d)*(sum[lst]-sum[d-1]);
	}
	return res;
}
int main(){
	scanf("%d",&tst);get_mu();
	while (tst--){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&K);
		printf("%d\n",get(b,d)-get(a-1,d)-get(b,c-1)+get(a-1,c-1));
	}
	return 0;
}
