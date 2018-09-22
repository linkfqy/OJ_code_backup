#include<cstdio>
typedef long long ll;

const int maxn=200005;
const double eps=1e-4;
int n,L,R,N,w[maxn];
double a[maxn],s[maxn];
ll X,Y,ansx=1,ansy=1,ws[maxn];
ll gcd(ll x,ll y) {return y==0?x:gcd(y,x%y);}
int que[2][maxn];
bool check(double ww){
	for (int i=1;i<=N;i++) a[i]=w[i]-ww,s[i]=s[i-1]+a[i];
	int hed[2]={1,1},til[2]={1,0};
	que[0][1]=0;
	for (int i=1;i<=N;i++){
		int t=i&1;
		while (hed[t]<=til[t]&&i-que[t][hed[t]]>R) hed[t]++;
		if (i>=L){
			int t=(i-L)&1;
			while (hed[t]<=til[t]&&s[que[t][til[t]]]>=s[i-L]) til[t]--;
			que[t][++til[t]]=i-L;
		}
		if (hed[t]<=til[t])
		if (L<=i-que[t][hed[t]]&&i-que[t][hed[t]]<=R)
		 if (s[i]-s[que[t][hed[t]]]>=eps)
		  {ansx=ws[i]-ws[que[t][hed[t]]];ansy=i-que[t][hed[t]];return 1;}
	}
	return 0;
}
int main(){
	scanf("%d%d%d",&n,&L,&R);N=2*n;
	for (int i=1;i<=n;i++) scanf("%d",&w[i]),w[i+n]=w[i];
	for (int i=1;i<=N;i++) ws[i]=ws[i-1]+w[i];
	check(3.5);
	double l=0,r=1e14;
	while (r-l>=eps){
		double mid=(l+r)/2;
		if (check(mid)) l=mid;else r=mid;
	}
	ll t=gcd(ansx,ansy);ansx/=t;ansy/=t;
	if (ansy==1) printf("%lld",ansx);else printf("%lld/%lld",ansx,ansy);
	return 0;
}
