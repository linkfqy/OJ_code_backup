#include<cstdio>
typedef long long ll;

const int maxn=1000005;
int n,stk[maxn];
int main(){
	scanf("%d",&n);
	int til=0; ll ans=0;
	for (int i=1;i<=n;i++){
		int x; scanf("%d",&x);
		while (til>=2&&stk[til-1]<x) ans+=stk[til-1],til--;
		if (til&&stk[til]<x) ans+=x,til--;
		stk[++til]=x;
	}
	while (til>=2) ans+=stk[til-1],til--;
	printf("%lld",ans);
	return 0;
}
