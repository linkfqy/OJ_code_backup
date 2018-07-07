#include<cstdio>
#include<algorithm>
#define lowbit(x) ((x)&-(x))
using namespace std;
typedef long long ll;
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

const int maxn=50005,maxm=100005;
int n,m,q;
struct data{
	int t,l,r,c;
}Q[maxn];
inline void add(ll *BIT,int x,int w){
	for (int i=x;i<=m;i+=lowbit(i)) BIT[i]+=w;
}
inline ll qry(ll *BIT,int x){
	int res=0;
	for (int i=x;i;i-=lowbit(i)) res+=BIT[i];
	return res;
}
ll c[maxm],cc[maxm];
inline void insert(int l,int r,int w){
	add(c,l,w);add(c,r+1,-w);
	add(cc,l,w*(l-1));add(cc,r+1,-w*r);
}
inline ll query(int l,int r){
	return qry(c,r)*r-qry(cc,r)-(qry(c,l-1)*(l-1)-qry(cc,l-1));
}
int ans[maxn],tem[maxn],id[maxn];
void divide(int L,int R,int l,int r){
	if (l>r) return;
	if (L==R){
		for (int i=l;i<=r;i++)
		 if (Q[id[i]].t==2) ans[id[i]]=L;
		return;
	}
	int mid=L+R>>1,pl=l-1,pr=r+1;
	for (int i=l;i<=r;i++)
	 if (Q[id[i]].t==1){
	 	if (Q[id[i]].c<=mid) tem[++pl]=id[i];
	 	 else tem[--pr]=id[i],insert(Q[id[i]].l,Q[id[i]].r,1);
	 }else{
	 	ll w=query(Q[id[i]].l,Q[id[i]].r);
	 	if (w>=Q[id[i]].c) tem[--pr]=id[i];
	 	 else tem[++pl]=id[i],Q[id[i]].c-=w;
	 }
	for (int i=l;i<=r;i++)
	 if (Q[id[i]].t==1&&Q[id[i]].c>mid) insert(Q[id[i]].l,Q[id[i]].r,-1);
	for (int i=l;i<=pl;i++) id[i]=tem[i];
	for (int i=pr;i<=r;i++) id[i]=tem[r+pr-i];
	divide(L,mid,l,pl);divide(mid+1,R,pr,r);
}
int main(){
	n=red(),q=red();m=n*2+2;
	int _max=0,_min=1e9;
	for (int i=1;i<=q;i++){
		Q[i].t=red();Q[i].l=red(),Q[i].r=red(),Q[i].c=red();
		id[i]=i;
		if (Q[i].t==1) _max=max(_max,Q[i].c),_min=min(_min,Q[i].c);
	}
	divide(_min,_max,1,q);
	for (int i=1;i<=q;i++)
	 if (Q[i].t==2) printf("%d\n",ans[i]);
	return 0;
}
