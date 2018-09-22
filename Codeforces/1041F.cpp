#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

const int maxn=100005;
int n,m,a[maxn],b[maxn],ty,ans;
map<int,int> numa,numb;
void calc(int l){
	numa.clear(); numb.clear();
	l++;int p=1; while (l--) p=p*2;
	for (int i=1;i<=n;i++) numa[a[i]%p]++;
	for (int i=1;i<=m;i++) numb[b[i]%p]++;
	for (int i=1;i<=n;i++)
	 ans=max(ans,numa[a[i]%p]+numb[(a[i]+p/2)%p]);
	for (int i=1;i<=m;i++)
	 ans=max(ans,numa[(a[i]+p/2)%p]+numb[a[i]%p]);
}
int main(){
	scanf("%d%d",&n,&ty);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d%d",&m,&ty);
	for (int i=1;i<=m;i++) scanf("%d",&b[i]);
	ans=2;
	for (int i=0;i<30;i++) calc(i);
	printf("%d",ans);
	return 0;
}
