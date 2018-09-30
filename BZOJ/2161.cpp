#include<cstdio>
#include<cstring>
#include<algorithm>
#define X first
#define Y second
#define mp make_pair
using namespace std;
typedef long long ll;

const int maxn=100005,maxs=400005,MOD=19921228;
int n,m,M,b[maxn*2],p[maxn],l[maxn],r[maxn],c[maxn];
void init(int *a,int add,int first,int mod,int prod)
{
    a[1]=first%mod;
    for (int i=2;i<=n;i++)
     a[i]=((ll)a[i-1]*prod+add+i)%mod;
}
pair<int,int> ev[maxn*2],q[maxn];
int s[maxs];
#define ls x<<1
#define rs x<<1|1
void ist(int x,int l,int r,int k,int w){
	if (l==r) {s[x]+=w;return;}
	int mid=l+r>>1;
	if (k<=mid) ist(ls,l,mid,k,w);else ist(rs,mid+1,r,k,w);
	s[x]=s[ls]+s[rs];
}
int qry(int x,int l,int r,int k){
	if (l==r) return l;
	int t=s[rs],mid=l+r>>1;
	if (t>=k) return qry(rs,mid+1,r,k);else return qry(ls,l,mid,k-t);
}
int main(){
	scanf("%d",&n);
	int Padd,Pfirst,Pmod,Pprod,Cadd,Cfirst,Cmod,Cprod,Ladd,Lfirst,Lmod,Lprod,Radd,Rfirst,Rmod,Rprod;
    scanf("%d%d%d%d",&Padd,&Pfirst,&Pmod,&Pprod);
    init(p,Padd,Pfirst,Pmod,Pprod);
    scanf("%d%d%d%d",&Cadd,&Cfirst,&Cmod,&Cprod);
    init(c,Cadd,Cfirst,Cmod,Cprod);
    scanf("%d%d%d%d",&Ladd,&Lfirst,&Lmod,&Lprod);
    init(l,Ladd,Lfirst,Lmod,Lprod);
    scanf("%d%d%d%d",&Radd,&Rfirst,&Rmod,&Rprod);
    init(r,Radd,Rfirst,Rmod,Rprod);
    for (int i=1;i<=n;i++) if (l[i]>=r[i]) swap(l[i],r[i]);
    memcpy(b,c,sizeof(c));
    sort(b+1,b+1+n); m=unique(b+1,b+1+n)-b-1;
    for (int i=1;i<=n;i++){
    	c[i]=lower_bound(b+1,b+1+m,c[i])-b;
    	q[i]=mp(p[i],i);
    	ev[++M]=mp(l[i],c[i]); ev[++M]=mp(r[i]+1,-c[i]);
	}
	sort(ev+1,ev+1+M);sort(q+1,q+1+n);
//	for (int i=1;i<=m;i++) if (i<=m-i+1) swap(b[i],b[m-i+1]);
	int ans=0;
	for (int i=1,j=1;i<=n;i++){
		while (j<=M&&ev[j].X<=q[i].X)
		 if (ev[j].Y>0) ist(1,1,m,ev[j++].Y,1);else ist(1,1,m,-ev[j++].Y,-1);
		if (s[1]>=q[i].Y) (ans+=b[qry(1,1,m,q[i].Y)])%=MOD;
	}
	printf("%d",ans);
	return 0;
}
