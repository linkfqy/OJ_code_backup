#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef long long ll;

const int maxn=200005;
int n,a[maxn],N;
bool vis[maxn];
struct data{
	int x,ty;
	data (int _x=0,int _ty=0):x(_x),ty(_ty) {}
	bool operator<(const data&b)const {return x<b.x;}
}b[maxn];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	 if (!vis[a[i]]) b[++N]=data(i,0),vis[a[i]]=1;
	cl(vis,0);
	int m=0;
	for (int i=n;i>=1;i--)
	 if (!vis[a[i]]) m++,b[++N]=data(i,1),vis[a[i]]=1;
	sort(b+1,b+1+N);
	ll ans=0;
	for (int i=1,j;i<=N;i=j){
		int num[2]; num[0]=num[1]=0;
		for (j=i;j<=N&&b[i].x==b[j].x;j++) num[b[j].ty]++;
		m-=num[1];
		ans+=num[0]*m;
	}
	printf("%lld",ans);
	return 0;
}
