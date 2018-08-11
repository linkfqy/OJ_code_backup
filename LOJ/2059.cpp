#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;

const int maxn=100005,maxs=2000005;
int n,m,q;
char s[maxn];
int sa[maxn],rk[maxn*2],t[maxn],buc[maxn],ht[maxn],f[maxn][17];
void get_sa(){
	cl(buc,0);
	for (int i=1;i<=n;i++) buc[rk[t[i]]]++;
	for (int i=1;i<=m;i++) buc[i]+=buc[i-1];
	for (int i=n;i;i--) sa[buc[rk[t[i]]]--]=t[i];
}
void make_sa(){
	m=128;
	for (int i=1;i<=n;i++) rk[i]=s[i],t[i]=i;
	get_sa();
	for (int k=1,p=0;k<n&&p<n;k<<=1,m=p){
		p=0;
		for (int i=n-k+1;i<=n;i++) t[++p]=i;
		for (int i=1;i<=n;i++) if (sa[i]>k) t[++p]=sa[i]-k;
		get_sa(); t[sa[1]]=p=1;
		for (int i=2;i<=n;i++)
		 if (rk[sa[i]]==rk[sa[i-1]]&&rk[sa[i]+k]==rk[sa[i-1]+k]) t[sa[i]]=p;else t[sa[i]]=++p;
		memcpy(rk,t,sizeof(t));
	}
	for (int i=1,h=0;i<=n;i++){
		if (h) h--;
		int j=sa[rk[i]-1];
		while (s[i+h]==s[j+h]) h++;
		ht[rk[i]]=h;
	} ht[1]=0;
	for (int i=1;i<=n;i++) f[i][0]=ht[i];
	for (int j=1;j<=16;j++)
	 for (int i=1;i<=n;i++)
	  f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1]);
}
int tre[maxs],ls[maxs],rs[maxs],len,Rot[maxn];
inline void pushup(int x) {tre[x]=tre[ls[x]]+tre[rs[x]];}
int build(int l,int r){
	int x=++len;tre[x]=0;
	if (l==r) return ls[x]=rs[x]=0,x;
	int mid=l+r>>1;
	ls[x]=build(l,mid); rs[x]=build(mid+1,r);
	return x;
}
int ist(int fa,int l,int r,int k){
	int x=++len; tre[x]=tre[fa]; ls[x]=ls[fa]; rs[x]=rs[fa];
	if (l==r) return tre[x]++,x;
	int mid=l+r>>1;
	if (k<=mid) ls[x]=ist(ls[fa],l,mid,k);
	 else rs[x]=ist(rs[fa],mid+1,r,k);
	pushup(x); return x;
}
int qry(int x,int y,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr) return tre[y]-tre[x];
	if (qr<l||r<ql) return 0;
	int mid=l+r>>1;
	return qry(ls[x],ls[y],l,mid,ql,qr)+qry(rs[x],rs[y],mid+1,r,ql,qr);
}
int main(){
	scanf("%d%d%s",&n,&q,s+1);
	make_sa();
	Rot[0]=build(1,n);
	for (int i=1;i<=n;i++) Rot[i]=ist(Rot[i-1],1,n,sa[i]);
	while (q--){
		int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
		int l=1,r=d-c+1,res=0;
		while (l<=r){
			int mid=l+r>>1,L=rk[c],R=rk[c];
			for (int j=16;j>=0;j--){
				if (L>(1<<j)&&f[L-(1<<j)+1][j]>=mid) L-=(1<<j);
				if (R+(1<<j)<=n&&f[R+1][j]>=mid) R+=(1<<j);
			}
			if (qry(Rot[L-1],Rot[R],1,n,a,b-mid+1)>0) res=mid,l=mid+1;else r=mid-1;
		}
		printf("%d\n",res);
	}
	return 0;
}
