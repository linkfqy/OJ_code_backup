#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=30005;
int n,q,ban[maxn],ida[maxn],idb[maxn],rka[maxn],rkb[maxn];
ll a[maxn],b[maxn],f[maxn],w1[maxn],w2[maxn],w3[maxn];
inline bool cmpa(int i,int j) {return a[i]<a[j];}
inline bool cmpb(int i,int j) {return b[i]<b[j];}
void calc(int i){
	w1[i]=w2[i]=w3[i]=-1e18;
	if (i>=1&&ban[i]!=i) w1[i]=a[i]*b[i];
	if (i>=2&&ban[i]!=i-1&&ban[i-1]!=i) w2[i]=a[i]*b[i-1]+a[i-1]*b[i];
	if (i>=3){
		if (ban[i]!=i-2&&ban[i-1]!=i&&ban[i-2]!=i-1) w3[i]=a[i]*b[i-2]+a[i-1]*b[i]+a[i-2]*b[i-1];
		if (ban[i]!=i-1&&ban[i-1]!=i-2&&ban[i-2]!=i) w3[i]=max(w3[i],a[i]*b[i-1]+a[i-1]*b[i-2]+a[i-2]*b[i]);
	}
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]),ida[i]=i;
	for (int i=1;i<=n;i++) scanf("%lld",&b[i]),idb[i]=i;
	sort(ida+1,ida+1+n,cmpa);sort(idb+1,idb+1+n,cmpb);
	sort(a+1,a+1+n);sort(b+1,b+1+n);
	for (int i=1;i<=n;i++) rka[ida[i]]=i,rkb[idb[i]]=i;
	for (int i=1;i<=n;i++) ban[rka[i]]=rkb[i];
	for (int i=1;i<=n;i++) calc(i);
	while (q--){
		int x,y;scanf("%d%d",&x,&y);
		x=rka[x]; y=rka[y]; swap(ban[x],ban[y]);
		for (int i=max(1,x-5);i<=min(n,x+5);i++) calc(i);
		for (int i=max(1,y-5);i<=min(n,y+5);i++) calc(i);
		f[0]=0;
		for (int i=1;i<=n;i++){
			f[i]=-1e16;
			if (i>=1) f[i]=max(f[i],f[i-1]+w1[i]);
			if (i>=2) f[i]=max(f[i],f[i-2]+w2[i]);
			if (i>=3) f[i]=max(f[i],f[i-3]+w3[i]);
		}
		printf("%lld\n",f[n]);
	}
	return 0;
}
