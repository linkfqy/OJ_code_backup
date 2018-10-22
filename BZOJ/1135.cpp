#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
inline char nc(){
	static char buf[100000],*l=buf,*r=buf;
	return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++;
}
inline int red(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
	return res*f;
}

const int maxn=200005,maxs=800005;
int n,m,q;ll K,d;
ll s[maxs],mx[maxs],lm[maxs],rm[maxs];
#define ls x<<1
#define rs x<<1|1
inline void pushup(int x){
	s[x]=s[ls]+s[rs];
	mx[x]=max(max(mx[ls],mx[rs]),rm[ls]+lm[rs]);
	lm[x]=max(lm[ls],s[ls]+lm[rs]);
	rm[x]=max(rm[rs],s[rs]+rm[ls]);
}
void build(int x,int l,int r){
	if (l==r) {s[x]=mx[x]=lm[x]=rm[x]=-K;return;}
	int mid=l+r>>1;
	build(ls,l,mid); build(rs,mid+1,r);
	pushup(x);
}
void ist(int x,int l,int r,int k,int w){
	if (l==r) {s[x]+=w;mx[x]=lm[x]=rm[x]=s[x];return;}
	int mid=l+r>>1;
	if (k<=mid) ist(ls,l,mid,k,w);else ist(rs,mid+1,r,k,w);
	pushup(x);
}
int main(){
	n=red(),q=red(),K=red(),d=red(),m=n-d;
	build(1,1,m);
	while (q--){
		int k=red(),w=red();
		ist(1,1,m,k,w);
		if (mx[1]<=K*d) puts("TAK");else puts("NIE");
	}
	return 0;
}
