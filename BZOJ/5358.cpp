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

const int maxn=100005,maxs=maxn*300;
int tst,n,q,a[maxn],p[maxn],lst[maxn];
bool vis[maxn];
void makeprime(int n){
	for (int i=2;i<=n;i++){
		if (!vis[i]) p[++p[0]]=i,lst[i]=i;
		for (int j=1;j<=p[0]&&i*p[j]<=n;j++){
			vis[i*p[j]]=1;lst[i*p[j]]=p[j];
			if (i%p[j]==0) break;
		}
	}
}
int id,Rot[maxs],s[maxs],ls[maxs],rs[maxs];
#define newnode (ls[++id]=0,rs[id]=0,s[id]=0,id)
void ist(int &x,int L,int R,int k){
	if (!x) x=newnode;
	if (L==R) {s[x]++;return;}
	int mid=L+R>>1;
	if (k<=mid) ist(ls[x],L,mid,k);else ist(rs[x],mid+1,R,k);
	s[x]=s[ls[x]]+s[rs[x]];
}
int qry(int &x,int L,int R,int ql,int qr){
	if (!x||L>R||qr<L||R<ql) return 0;
	if (ql<=L&&R<=qr) return s[x];
	int mid=L+R>>1;
	return qry(ls[x],L,mid,ql,qr)+qry(rs[x],mid+1,R,ql,qr);
}
inline bool check(int d,int l,int r){
	for (int j=d;j>1;){
		int x=lst[j],tot=0;
		while (j%x==0) tot++,j/=x;
		if (qry(Rot[x],1,n,l,r)<tot) return 0;
	}
	return 1;
}
int main(){
	tst=red(); makeprime(1e5);
	while (tst--){
		n=red(),q=red();
		cl(Rot,0);id=0;
		for (int i=1;i<=n;i++){
			int x=a[i]=red();
			for (int j=x;j>1;j=j/lst[j])
				ist(Rot[lst[j]],1,n,i);
		}
		while (q--){
			int l=red(),r=red(),d=red();
			printf(check(d,l,r)?"Yes\n":"No\n");
		}
	}
	return 0;
}
