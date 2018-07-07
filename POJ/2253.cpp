#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=205,maxe=40005;
int n,e,x[maxn],y[maxn],fa[maxn],total=0;
struct ha{
	int x,y;double w;
	bool operator<(const ha&b)const{
		return w<b.w;
	}
}a[maxe];
int getfa(int x){
	if (fa[x]==x) return x;
	return fa[x]=getfa(fa[x]);
}
void kruskal(){
	for (int i=1;i<=e;i++){
		int fx=getfa(a[i].x),fy=getfa(a[i].y);
		if (fx==fy) continue;
		fa[fx]=fy;
		if (getfa(1)==getfa(2)) {printf("Frog Distance = %.3lf\n\n",a[i].w);return;}
	}
}
int main(){
	scanf("%d",&n);
	while (n){
		total++;e=0;
		printf("Scenario #%d\n",total);
		for (int i=1;i<=n;i++){
			scanf("%d%d",&x[i],&y[i]);fa[i]=i;
			for (int j=1;j<i;j++)
			 a[++e].x=i,a[e].y=j,a[e].w=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
		}
		sort(a+1,a+1+e);
		kruskal();
		scanf("%d",&n);
	}
	return 0;
}
