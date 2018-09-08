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

const int maxn=1000005;
int n,c,q,BIT[maxn],a[maxn],nxt[maxn],cc[maxn],ans[maxn];
struct data{
	int X,Y,id;
	bool operator<(const data&b)const {return X<b.X;}
}Q[maxn];
#define lowbit(x) ((x)&-(x))
inline void ist(int x,int w){
	for (int i=x;i<=n;i+=lowbit(i)) BIT[i]+=w;
}
inline int qry(int x){
	int res=0;
	for (int i=x;i>=1;i-=lowbit(i)) res+=BIT[i];
	return res;
}
int main(){
	n=red(),c=red(),q=red();
	for (int i=1;i<=c;i++) cc[i]=n+1;nxt[n+1]=n+1;
	for (int i=1;i<=n;i++) a[i]=red();
	for (int i=n;i;i--) nxt[i]=cc[a[i]],cc[a[i]]=i;
	for (int i=1;i<=q;i++) Q[i].X=red(),Q[i].Y=red(),Q[i].id=i;
	sort(Q+1,Q+1+q);
	for (int i=1;i<=n;i++) ist(nxt[i],1),ist(nxt[nxt[i]],-1);
	for (int i=1,l=1;i<=q;i++){
		while (l<Q[i].X) ist(nxt[l],-1),ist(nxt[nxt[l]],1),l++;
		ans[Q[i].id]=qry(Q[i].Y);
	}
	for (int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
