#include<cstdio>
#include<algorithm>
#define lowbit(x) ((x)&-(x))
using namespace std;
inline char nc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int red(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
	return res*f;
}

const int maxn=505,maxs=250005,maxq=60005;
int n,q,nn,max_ai;
struct question{
	int x,y,xx,yy,k;
}Q[maxq];
struct data{
	int x,y,w;
	bool operator<(const data&b)const{
		return w<b.w;
	}
}a[maxs];
int tem[maxq],id[maxq],ans[maxq],BIT[maxn][maxn];
inline void add(int x,int y,int w){
	for (int i=x;i<=n;i+=lowbit(i))
	 for (int j=y;j<=n;j+=lowbit(j))
	  BIT[i][j]+=w;
}
inline int qry(int x,int y){
	int res=0;
	for (int i=x;i;i-=lowbit(i))
	 for (int j=y;j;j-=lowbit(j))
	  res+=BIT[i][j];
	return res;
}
inline int ID(int w){
	data x;x.w=w;
	return lower_bound(a+1,a+1+nn,x)-a;
}
void divide(int L,int R,int l,int r){
	if (l>r) return;
	if (L==R){
		for (int i=l;i<=r;i++) ans[id[i]]=L;
		return;
	}
	int mid=L+R>>1,pl=l-1,pr=r+1,st=ID(L),gl=ID(mid+1);
	for (int i=st;i<gl;i++) add(a[i].x,a[i].y,1);
	for (int i=l;i<=r;i++){
		int w=qry(Q[id[i]].xx,Q[id[i]].yy)-qry(Q[id[i]].x-1,Q[id[i]].yy)-qry(Q[id[i]].xx,Q[id[i]].y-1)+qry(Q[id[i]].x-1,Q[id[i]].y-1);
		if (w>=Q[id[i]].k) tem[++pl]=id[i];else tem[--pr]=id[i],Q[id[i]].k-=w;
	}
	for (int i=st;i<gl;i++) add(a[i].x,a[i].y,-1);
	for (int i=l;i<=r;i++) id[i]=tem[i];
	divide(L,mid,l,pl);divide(mid+1,R,pr,r);
}
int main(){
	n=red(),q=red();
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=n;j++){
	 	a[++nn].x=i;a[nn].y=j;
	 	a[nn].w=red();max_ai=max(max_ai,a[nn].w);
	 }
	sort(a+1,a+1+nn);
	for (int i=1;i<=q;i++){
		Q[i].x=red(),Q[i].y=red();id[i]=i;
		Q[i].xx=red(),Q[i].yy=red();Q[i].k=red();
	}
	divide(0,max_ai,1,q);
	for (int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
