#include<cstdio>
#include<cstdlib>
#include<map>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
#define c(x) ((x)*((x)+1)/2)

const int maxn=200005;
int n,m;
ull a[maxn],A[maxn],s[maxn],d[maxn],ans;
map<ull,ull> num,sum;
int main(){
	srand(998244353);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		int x,y;scanf("%d%d",&x,&y); ull w=(ull)rand()*rand()*rand()+(ull)rand()*rand()+rand();
		a[x]^=w;a[y+1]^=w; A[x]^=w;
	}
	for (int i=1;i<=m;i++)
	 a[i]^=a[i-1],s[i]=s[i-1]^a[i],d[i]=d[i-1]^A[i];
	for (int i=1;i<=m;i++){
		ull w=s[i]^d[i];
		num[w]++;sum[w]+=i-1;
		ans+=num[w]*i-sum[w];
	}
	for (int i=1,j=0;i<=m;i++)
	 if (a[i]==0) ans-=c((ull)i-j);
	 else j=i;
	printf("%lld",ans);
	return 0;
}
