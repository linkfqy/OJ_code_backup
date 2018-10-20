#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;

const int maxn=25;
int n,m,l[maxn],r[maxn],lid[maxn],rid[maxn];
int main(){
	scanf("%d%d",&n,&m);
	cl(r,63);
	for (int i=1;i<=n;i++){
		int li,ri,d;scanf("%d%d%d",&li,&ri,&d);
		if (l[d]<li) l[d]=li,lid[d]=i;
		if (r[d]>ri) r[d]=ri,rid[d]=i;
	}
	for (int i=1;i<=m;i++)
	 if (r[i]<l[i]) printf("TAK %d %d\n",rid[i],lid[i]);
	 else puts("NIE");
	return 0;
}
