#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1005;
int n,Q[maxn];
int main(){
	scanf("%d",&n);
	int til=0;Q[0]=0xc0c0c0c0;
	for (int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		if (Q[til]<x) Q[++til]=x;else
		*lower_bound(Q,Q+til+1,x)=x;
	}
	printf("%d",til);
	return 0;
}
