#include<cstdio>
#include<algorithm>
#define mp make_pair
#define X first
#define Y second
using namespace std;

const int maxn=200005;
int n,m;
pair<int,int> a[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<=n;i++) scanf("%d",&a[i].X),a[i].Y=i;
	sort(a,a+1+n);
	int t=a[0].Y;
	for (int i=1;i<=n;i++)
	 printf("%d ",a[t].X),t=a[t].Y;
	return 0;
}
