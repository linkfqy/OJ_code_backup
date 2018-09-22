#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

ll gcd(ll x,ll y) {return y==0?x:gcd(y,x%y);}
int main(){
	ll a,b,x,y;
	scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
	ll t=gcd(x,y);x/=t;y/=t;
	printf("%lld",min(a/x,b/y));
	return 0;
}
