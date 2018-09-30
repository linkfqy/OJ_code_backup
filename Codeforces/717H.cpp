#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define X first
#define Y second
using namespace std;

const int maxn=100005,maxt=1000005;
int n,e,T,t[maxn][21],belong[maxn],c[maxt];
pair<int,int> a[maxn];
bool work(){
	for (int i=1;i<=n;i++) belong[i]=t[i][rand()%t[i][0]+1];
	for (int i=1;i<=T;i++) c[i]=(rand()&1);
	int res=0;
	for (int i=1;i<=e;i++) res+=(c[belong[a[i].X]]!=c[belong[a[i].Y]]);
	return res*2>=e;
}
int main(){
	scanf("%d%d",&n,&e);
	for (int i=1;i<=e;i++) scanf("%d%d",&a[i].X,&a[i].Y);
	for (int i=1;i<=n;i++){
		scanf("%d",&t[i][0]);
		for (int j=1;j<=t[i][0];j++) scanf("%d",&t[i][j]),T=max(T,t[i][j]);
	}
	while (!work());
	for (int i=1;i<=n;i++) printf("%d ",belong[i]);puts("");
	for (int i=1;i<=T;i++) printf("%d ",c[i]+1);
	return 0;
}
