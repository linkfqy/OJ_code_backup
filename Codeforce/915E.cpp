#include<cstdio>
#include<cstring>
#define cl(x,y) memset(x,y,sizeof(x))
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

const int maxs=300000*50;
int n,q;
int rt,id,s[maxs],ls[maxs],rs[maxs],tag[maxs];
inline void pushdown(int x,int L,int R){
	if (tag[x]<0) return;
	if (L==R) return;
	if (!ls[x]) ls[x]=++id;
	if (!rs[x]) rs[x]=++id;
	int mid=L+R>>1;
	tag[ls[x]]=tag[x]; s[ls[x]]=(mid-L+1)*tag[x];
	tag[rs[x]]=tag[x]; s[rs[x]]=(R-mid)*tag[x];
	tag[x]=-1;
}
void ist(int &x,int L,int R,int ql,int qr,int k){
	if (L>R||R<ql||qr<L) return;
	if (!x) x=++id;
	if (ql<=L&&R<=qr) {tag[x]=k,s[x]=(R-L+1)*k;return;}
	int mid=L+R>>1;
	pushdown(x,L,R);
	ist(ls[x],L,mid,ql,qr,k); ist(rs[x],mid+1,R,ql,qr,k);
	s[x]=s[ls[x]]+s[rs[x]];
}
int main(){
	n=red(),q=red();cl(tag,255);
	while (q--){
		int l=red(),r=red(),c=red();
		if (c==1) ist(rt,1,n,l,r,1);else ist(rt,1,n,l,r,0);
		printf("%d\n",n-s[rt]);
	}
	return 0;
}
