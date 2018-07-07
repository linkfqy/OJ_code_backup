#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
#define abs_(x) ((x)>0?(x):-(x))

const int maxn=100005;
int N,M,n,a[maxn],BIT[maxn];
ll ans=0;
pair<int,int> b[maxn];
#define lowbit(x) ((x)&-(x))
inline void ist(int x,int w) {for (int i=x;i<=n;i+=lowbit(i)) BIT[i]+=w;}
inline int ask(int x) {int res=0;for (int i=x;i;i-=lowbit(i)) res+=BIT[i];return res;}
int main(){
	scanf("%d%d",&N,&M);
	for (int i=N;i;i--) scanf("%d",&a[i]),b[++n]=make_pair(a[i],N-n+1);
	for (int i=1;i<=M;i++) scanf("%d",&a[i+N]),b[++n]=make_pair(a[i+N],n);
	sort(b+1,b+1+n);
	for (int i=1;i<=n;i++) ist(i,1);
	for (int t=n,i=N;t;t--)
	 if (i<b[t].second) ans+=ask(b[t].second-1)-ask(i),i=b[t].second-1,ist(b[t].second,-1);
	 else ans+=ask(i)-ask(b[t].second),i=b[t].second,ist(b[t].second,-1);
	printf("%lld",ans);
	return 0;
}
