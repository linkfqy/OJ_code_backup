#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=100005;
int n,q,fa[maxn];
ll BIT[maxn],a[maxn];
inline int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
#define lowbit(x) ((x)&-(x))
inline void ist(int x,ll w){
	for (int i=x;i<=n;i+=lowbit(i)) BIT[i]+=w;
}
inline ll qry(int x){
	ll res=0;
	for (int i=x;i;i-=lowbit(i)) res+=BIT[i];
	return res;
}
void change(int l,int r){
	for (int i=getfa(l);i<=r;i=getfa(i+1)){
		ist(i,(ll)sqrt(a[i])-a[i]);a[i]=sqrt(a[i]);
		if (a[i]<=1) fa[getfa(i)]=getfa(i+1);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]),fa[i]=i,ist(i,a[i]);fa[n+1]=n+1;
	scanf("%d",&q);
	while (q--){
		int c,l,r;scanf("%d%d%d",&c,&l,&r);
		if (l>r) swap(l,r);
		if (c==1) printf("%lld\n",qry(r)-qry(l-1));else change(l,r);
	}
	return 0;
}
