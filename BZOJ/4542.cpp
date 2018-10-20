#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=100005;
int n,q,p,m,h[maxn];
char S[maxn];
ll s[maxn],inv[maxn],w[maxn],b[maxn],cnt[maxn],ans[maxn],now=0;
ll power(ll a,int b){
	ll res=1,w=a%p;
	while (b){
		if (b&1) (res*=w)%=p;
		(w*=w)%=p;
		b>>=1;
	}
	return res;
}
inline void blocker(){
	int k=sqrt(n);
	for (int i=1;i<=n;i++) h[i]=(i-1)/k+1;
}
struct data{
	int l,r,id;
	bool operator<(const data&b)const{
		if (h[l]==h[b.l]) return r<b.r;
		return l<b.l;
	}
}a[maxn];
#define c2(x) ((x)*((x)-1)/2)
inline void update(int x,int d){
	now-=c2(cnt[w[x]]);
	cnt[w[x]]+=d;
	now+=c2(cnt[w[x]]);
}
ll c[maxn],num;
int main(){
	scanf("%d%s%d",&p,S+1,&q);
	n=strlen(S+1);
	for (int i=1;i<=n;i++) s[i]=(s[i-1]*10+S[i]-'0')%p;
	if (p==2||p==5){
		for (int i=1;i<=n;i++) c[i]=c[i-1]+(s[i]==0)*i,cnt[i]=cnt[i-1]+(s[i]==0);
		for (int i=1;i<=q;i++){
			int l,r;scanf("%d%d",&l,&r);
			printf("%lld\n",c[r]-c[l-1]-(cnt[r]-cnt[l-1])*(l-1));
		}
		return 0;
	}
	inv[0]=1;inv[1]=power(10,p-2);
	for (int i=2;i<=n;i++) inv[i]=(inv[i-1]*inv[1])%p;
	for (int i=0;i<=n;i++) w[i]=b[i]=inv[i]*s[i]%p;
	sort(b,b+1+n); m=unique(b,b+1+n)-b-1;
	for (int i=0;i<=n;i++) w[i]=lower_bound(b,b+1+m,w[i])-b;
	blocker();
	for (int i=1;i<=q;i++) scanf("%d%d",&a[i].l,&a[i].r),a[i].id=i,a[i].l--;
	sort(a+1,a+1+q);
	int L=1,R=1; update(1,1);
	for (int i=1;i<=q;i++){
		while (L>a[i].l) update(--L,1);
		while (L<a[i].l) update(L++,-1);
		while (R>a[i].r) update(R--,-1);
		while (R<a[i].r) update(++R,1);
		ans[a[i].id]=now;
	}
	for (int i=1;i<=q;i++) printf("%lld\n",ans[i]);
	return 0;
}
