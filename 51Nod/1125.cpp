#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;

const int maxn=50005,INF=0x3f3f3f3f;
int n,a[maxn],id[maxn],MIN=INF;
LL ans;
bool vis[maxn];
bool mycomp(const int&i,const int&j){
	return a[i]<a[j];
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	 scanf("%d",&a[i]),id[i]=i,MIN=min(MIN,a[i]);
	sort(id+1,id+1+n,mycomp);
	for (int i=1;i<=n;i++)
	 if (!vis[i]){
	 	LL tot=0,Min=INF,sum=0;//printf("%d ",i);
	 	for (int j=i;!vis[j];j=id[j]){//printf("%d ",j);
	 		vis[j]=1;Min=min(Min,(LL)a[j]);
			sum+=a[j];tot++;
		}//putchar('\n');
		ans+=min((tot-2)*Min+sum,MIN+Min+tot*MIN+sum);
	 }
	printf("%lld",ans);
	return 0;
}
