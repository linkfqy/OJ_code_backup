#include<cstdio>
#include<cstring>
#define cl(x,y) memset(x,y,sizeof(x))
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

const int maxn=100005,maxs=400005;
int n,q,a[maxn][10];
ll s[maxs][10]; int to[maxs][10];
inline void pushup(int x){
	for (int i=0;i<=9;i++) s[x][i]=s[x<<1][i]+s[x<<1|1][i];
}
void build(int x,int l,int r){
	for (int i=0;i<=9;i++) to[x][i]=i;
	if (l==r){
		for (int i=0;i<=9;i++) s[x][i]=a[l][i];
		return;
	}
	int mid=l+r>>1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	pushup(x);
}
inline void addto(int x,int *tg){
	static ll tmp[10]; cl(tmp,0);
	for (int i=0;i<=9;i++) tmp[i]=tg[to[x][i]];
	for (int i=0;i<=9;i++) to[x][i]=tmp[i];
	cl(tmp,0);
	for (int i=0;i<=9;i++) tmp[tg[i]]+=s[x][i];
	for (int i=0;i<=9;i++) s[x][i]=tmp[i];
}
inline void pushdown(int x){
	bool suc=1; 
	for (int i=0;i<=9;i++) if (to[x][i]!=i) suc=0;
	if (suc) return;
	addto(x<<1,to[x]);addto(x<<1|1,to[x]);
	for (int i=0;i<=9;i++) to[x][i]=i;
}
void ist(int x,int l,int r,int ql,int qr,int *tg){
	if (ql<=l&&r<=qr) {addto(x,tg);return;}
	if (qr<l||r<ql) return;
	int mid=l+r>>1; pushdown(x);
	ist(x<<1,l,mid,ql,qr,tg);ist(x<<1|1,mid+1,r,ql,qr,tg);
	pushup(x);
}
ll qry(int x,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr){
		ll res=0;
		for (int i=0;i<=9;i++) res+=s[x][i]*i;
		return res;
	}
	if (qr<l||r<ql) return 0;
	int mid=l+r>>1; pushdown(x);
	return qry(x<<1,l,mid,ql,qr)+qry(x<<1|1,mid+1,r,ql,qr);
}
int main(){
	n=red(),q=red();
	for (int i=1;i<=n;i++){
		int x=red(),w=1;
		while (x) a[i][x%10]+=w,w*=10,x/=10;
	}
	build(1,1,n);
	while (q--)
	 if (red()==1){
	 	int l=red(),r=red(),x=red(),y=red(),t[10];
	 	for (int i=0;i<=9;i++) t[i]=i;t[x]=y;
	 	ist(1,1,n,l,r,t);
	 }else{
	 	int l=red(),r=red();
	 	printf("%lld\n",qry(1,1,n,l,r));
	 }
	return 0;
}
