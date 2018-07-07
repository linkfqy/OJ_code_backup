#include<cstdio>
#include<cstring>
typedef long long ll;

int tst,len,a[25];
ll n,f[25][15];
ll dfs(int stp,int lst,bool lt){
	if (stp==0) return 1;
	if (lt&&f[stp][lst]>0) return f[stp][lst];
	int now=lt?9:a[stp];
	ll res=0;
	for (int i=0;i<=now;i++)
	 if (!(i==9&&lst==4)) res+=dfs(stp-1,i,lt||i<now);
	if (lt) f[stp][lst]=res;
	return res;
}
int main(){
	scanf("%d",&tst);
	memset(f,255,sizeof(f));
	while (tst--){
		scanf("%lld",&n);
		len=0;
		for (ll x=n;x;x/=10) a[++len]=x%10;
		printf("%lld\n",n+1-dfs(len,0,0));
	}
	return 0;
}
