#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;

const int maxn=20005;
int n,ans[maxn];
bool vis[maxn];
struct point{
	int x,y,id;
	bool f;
	point() {}
	point(int _x,int _y):x(_x),y(_y) {}
	bool operator<(const point&b)const{
		return x<b.x||x==b.x&&y<b.y;
	}
}a[maxn],b[maxn],p;
typedef point vec;
inline vec operator-(const vec&a,const vec&b){
	return vec(a.x-b.x,a.y-b.y);
}
inline int cross(const vec&a,const vec&b){
	return a.x*b.y-a.y*b.x;
}
bool cmp(const point&a,const point&b){
	return cross(a-p,b-p)>0;
}
void divide(int l,int r){
	if (l>=r) return;
	for (int i=l;i<=r;i++) b[i]=a[i];
	swap(*min_element(a+l,a+r+1),a[r]);
	p=a[r];
	sort(a+l,a+r,cmp); cl(vis,0);
	int i,j,t,mid;
	for (i=l,t=0;i<r;vis[i]=1,t+=a[i].f?1:-1,i++)
	 if ((p.f^a[i].f)&&t==0) break;
	mid=i;
	if (!p.f) ans[p.id]=a[i].id;else ans[a[i].id]=p.id;
	divide(l,mid-1);divide(mid+1,r-1);
	for (int i=l;i<=r;i++) a[i]=b[i];
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y),a[i].id=i,a[i].f=0;
	for (int i=n+1;i<=n+n;i++) scanf("%d%d",&a[i].x,&a[i].y),a[i].id=i,a[i].f=1;
	divide(1,2*n);
	for (int i=1;i<=n;i++) printf("%d\n",ans[i]-n);
	return 0;
}
