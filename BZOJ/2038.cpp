#include<cstdio>
#include<algorithm>
#include<cmath>
#define LL long long
using namespace std;
const int maxn=50005;
int n,q,a[maxn],h[maxn],hsh[maxn];
LL now;
LL c2(int x) {return (LL)x*(x-1)/2;}
LL gcd(LL x,LL y){
	if (y==0) return x;
	return gcd(y,x%y);
}
struct data{
	int l,r,id;
	bool operator<(const data&b)const{
		if (h[l]==h[b.l]) return r<b.r;
		return l<b.l;
	}
}que[maxn];
struct la{
	LL x,y;
}ans[maxn];
inline int red(){
	int tot=0,f=1;char ch=getchar();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=getchar();}
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return f*tot;
}
void blocker(){
	int k=sqrt(n);
	for (int i=1;i<=n;i++) h[i]=(i-1)/k+1;
}
void update(int x,int d){
	now-=c2(hsh[a[x]]);
	hsh[a[x]]+=d;
	now+=c2(hsh[a[x]]);
}
int main(){
	n=red(),q=red();
	for (int i=1;i<=n;i++) a[i]=red();
	blocker();
	for (int i=1;i<=q;i++) que[i].l=red(),que[i].r=red(),que[i].id=i;
	sort(que+1,que+1+q);
	update(1,1);
	for (int i=1,L=1,R=1;i<=q;i++){
		while (L<que[i].l) update(L++,-1);
		while (L>que[i].l) update(--L,1);
		while (R<que[i].r) update(++R,1);
		while (R>que[i].r) update(R--,-1);
		ans[que[i].id]=(la){now,c2(que[i].r-que[i].l+1)};
	}
	for (int i=1;i<=q;i++){
		LL t=gcd(ans[i].x,ans[i].y);
		ans[i].x/=t;ans[i].y/=t;
		if (ans[i].x==0) printf("0/1\n");else printf("%lld/%lld\n",ans[i].x,ans[i].y);
	}
	return 0;
}
