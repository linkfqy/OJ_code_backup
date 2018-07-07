#include<cstdio>
#include<queue>
using namespace std;
typedef long long LL;

const int maxn=100005,INF=0x3f3f3f3f;
int n,k,a[maxn],L[maxn],R[maxn];
bool vis[maxn];
LL ans;
struct data{
	int id,x;
	data () {}
	data (int _id,int _x):id(_id),x(_x) {}
	bool operator<(const data&b)const{
		return x>b.x;
	}
};
priority_queue<data> Q;
int main(){
	int lst;scanf("%d%d%d",&n,&k,&lst);
	for (int i=1;i<n;i++){
		int x;scanf("%d",&x);L[i]=i-1;R[i]=i+1;
		a[i]=x-lst;lst=x;Q.push(data(i,a[i]));
	}
	n--;a[0]=INF;a[n+1]=INF;
	R[0]=1;L[n+1]=n;L[0]=0;R[n+1]=n+1;
	for (int i=1;i<=k;i++){
		while (Q.top().id!=R[L[Q.top().id]]||Q.top().id!=L[R[Q.top().id]]) Q.pop();
		data x=Q.top();Q.pop();
		ans+=x.x;
		a[x.id]=a[L[x.id]]+a[R[x.id]]-x.x;
		Q.push(data(x.id,a[x.id]));
		R[L[x.id]=L[L[x.id]]]=x.id;
		L[R[x.id]=R[R[x.id]]]=x.id;
	}
	printf("%lld",ans);
	return 0;
}
