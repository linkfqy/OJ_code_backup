#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;

const int maxn=100005,tt=1000000007;
int n,topo,topa;
struct data{
	int l,w;
	data () {}
	data (int _l,int _w):l(_l),w(_w) {}
	bool operator==(const data&b)const{
		return w==b.w;
	}
}o[maxn],a[maxn];
void merge(data *a,int &n){
//	n=unique(a+1,a+1+n)-a-1;
	int m=1;
	for (int i=2;i<=n;i++)
	 if (a[i].w!=a[i-1].w) a[++m]=a[i];
	n=m;
}
int main(){
	scanf("%d",&n);
	topo=topa=0;int ans=0;
	for (int k=1;k<=n;k++){
		int x;scanf("%d",&x);
		for (int j=1;j<=topa;j++) a[j].w&=x;
		for (int j=1;j<=topo;j++) o[j].w|=x;
		a[++topa]=data(k,x); o[++topo]=data(k,x);
		merge(o,topo);merge(a,topa);
		for (int i=topa,j=topo,lst=k;i&&j;){
			int t=max(a[i].l,o[j].l);
			ans=(ans+(LL)a[i].w*o[j].w%tt*(lst-t+1)%tt)%tt;
			i-=(t==a[i].l);j-=(t==o[j].l);lst=t-1;
		}
	}
	printf("%d",ans);
	return 0;
}
