#include<cstdio>
#include<algorithm>
using namespace std;
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

const int maxn=500005,maxs=2000005;
int n,q,a[maxn];
struct node{
	int s,lm,rm,mx;
	inline void get(int x) {s=lm=rm=mx=x;}
}tre[maxs],null;
inline node operator+(const node&a,const node&b){
	node res;
	res.s=a.s+b.s;
	res.lm=max(a.lm,a.s+b.lm);
	res.rm=max(b.rm,b.s+a.rm);
	res.mx=max(max(max(a.mx,b.mx),max(res.lm,res.rm)),a.rm+b.lm);
	return res;
}
void build(int x,int l,int r){
	if (l==r) {tre[x].get(a[l]);return;}
	int mid=l+r>>1;
	build(x<<1,l,mid); build(x<<1|1,mid+1,r);
	tre[x]=tre[x<<1]+tre[x<<1|1];
}
void ist(int x,int l,int r,int k,int w){
	if (l==r) {tre[x].get(w);return;}
	int mid=l+r>>1;
	if (k<=mid) ist(x<<1,l,mid,k,w);
	 else ist(x<<1|1,mid+1,r,k,w);
	tre[x]=tre[x<<1]+tre[x<<1|1];
}
node qry(int x,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr) return tre[x];
	if (qr<l||r<ql) return null;
	int mid=l+r>>1;
	return qry(x<<1,l,mid,ql,qr)+qry(x<<1|1,mid+1,r,ql,qr);
}
int main(){
	n=red(),q=red(); null.get(0xc0c0c0c0);null.s=0;
	for (int i=1;i<=n;i++) a[i]=red();
	build(1,1,n);
	while (q--)
	 if (red()==1){
	 	int l=red(),r=red();
	 	if (l>r) swap(l,r);
	 	printf("%d\n",qry(1,1,n,l,r).mx);
	 }else{
	 	int k=red(),w=red();
	 	ist(1,1,n,k,w);
	 }
	 return 0;
}
