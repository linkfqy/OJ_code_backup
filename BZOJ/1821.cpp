#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn=1005,maxe=1000005;
int n,K,e,x[maxn],y[maxn],fa[maxn];
struct edge{
	int x,y;double w;
	edge () {}
	edge (int _x,int _y,double _w):x(_x),y(_y),w(_w) {}
	inline bool operator<(const edge&b)const {return w<b.w;}
}a[maxe];
inline double sqr(double x) {return x*x;}
inline int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int main(){
	scanf("%d%d",&n,&K);e=0;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		for (int j=1;j<i;j++) a[++e]=edge(i,j,sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j])));
	}
	sort(a+1,a+1+e);
	int tot=n; for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=e;i++)
	 if (getfa(a[i].x)!=getfa(a[i].y)){
	 	fa[getfa(a[i].x)]=getfa(a[i].y);
	 	if (--tot==K) break;
	 }
	for (int i=1;i<=e;i++)
	 if (getfa(a[i].x)!=getfa(a[i].y))
	  return printf("%.2lf",a[i].w);
	return 0;
}
