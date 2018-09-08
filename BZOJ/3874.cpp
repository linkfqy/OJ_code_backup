#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=205;
int n,N; ll m,f;
struct data{
	ll s,p;
	inline bool operator<(const data&b)const {return s<b.s;}
}a[maxn],b[maxn];
ll calc(ll k){
	ll M=m-k*f,res=0,day=0,t;
	for (int i=1;i<=n;i++){
		if (a[i].s>=day)
		 t=min(a[i].s-day+1,M/a[i].p/k),day+=t,res+=t*k,M-=t*k*a[i].p;
		if (a[i].s>=day)
		 t=M/a[i].p,day++,res+=t,M-=t*a[i].p;
	}
	return res;
}
int main(){
	scanf("%lld%lld%d",&m,&f,&N);
	for (int i=1;i<=N;i++) scanf("%lld%lld",&b[i].p,&b[i].s);
	for (int i=1;i<=N;i++){
		bool suc=1;
		for (int j=1;j<=N;j++)
		 if (b[i].p>b[j].p&&b[i].s<b[j].s) {suc=0;break;}
		if (suc) a[++n]=b[i];
	}
	sort(a+1,a+1+n);
	ll l=1,r=m/f,ans=0;
	while (l<=r){
		ll mid1=l+(r-l)/3,mid2=r-(r-l)/3,c1=calc(mid1),c2=calc(mid2);
		ans=max(ans,max(c1,c2));
		if (c1<c2) l=mid1+1;else r=mid2-1;
	}
	printf("%lld",ans);
	return 0;
}
