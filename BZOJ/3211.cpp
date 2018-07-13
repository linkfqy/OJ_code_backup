#include<cstdio>
#include<cmath>
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

const int maxn=100005;
int n,q,fa[maxn],a[maxn];
ll BIT[maxn];
inline int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
#define lowbit(x) ((x)&-(x))
inline void ist(int x,int w){
	for (int i=x;i<=n;i+=lowbit(i)) BIT[i]+=w;
}
inline ll qry(int x){
	ll res=0;
	for (int i=x;i;i-=lowbit(i)) res+=BIT[i];
	return res;
}
void change(int l,int r){
	for (int i=getfa(l);i<=r;i=getfa(i+1)){
		ist(i,(int)sqrt(a[i])-a[i]);a[i]=sqrt(a[i]);
		if (a[i]<=1) fa[getfa(i)]=getfa(i+1);
	}
}
int main(){
	n=red();
	for (int i=1;i<=n;i++) a[i]=red(),fa[i]=i,ist(i,a[i]);fa[n+1]=n+1;
	q=red();
	while (q--){
		int c=red(),l=red(),r=red();
		if (c==1) printf("%lld\n",qry(r)-qry(l-1));else change(l,r);
	}
	return 0;
}
