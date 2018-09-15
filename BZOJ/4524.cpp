#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=130;
ll n,k;
struct data{
	ll x;int p,t,pre;
	data () {}
	data (ll _x,int _p,int _t,int _pre):x(_x),t(_t),pre(_pre),p(_p) {}
	inline bool operator<(const data&b)const {return x<b.x;}
};
priority_queue<data> Q;
int p[maxn]; bool vis[maxn];
void makep(int n){
	for (int i=2;i<=n;i++){
		if (!vis[i]) p[++p[0]]=i;
		for (int j=1;j<=p[0]&&i*p[j]<=n;j++){
			vis[i*p[j]]=1;
			if (i%p[j]==0) break;
		}
	}
}
int main(){
	scanf("%lld%lld",&n,&k);k--;
	makep(128);
	for (int i=1;i<=p[0];i++){
		int t=1;ll x=p[i];
		while (x<=n) Q.push(data(x,p[i],t,i-1)),x*=p[i],t++;
	}
	while (k--){
		data m=Q.top();Q.pop();
		if (m.t==1) continue;
		for (int i=1;i<=m.pre;i++)
		 Q.push(data(m.x/m.p*p[i],m.p,m.t-1,i));
	}
	printf("%lld",Q.top().x);
	return 0;
}
