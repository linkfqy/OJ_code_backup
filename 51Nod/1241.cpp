#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=50005;
int n,f[maxn];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	int ans=0;
	for (int i=1;i<=n;i++) ans=max(ans,f[i]);
	return printf("%d",n-ans),0;
}
