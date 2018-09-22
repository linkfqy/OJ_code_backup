#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=200005,maxs=20000005;
int n,q,w1,w2,a[maxn];
int ls[maxs],rs[maxs],len,Lrot[maxn],Rrot[maxn];
ll s[maxs],ad[maxs];
int ist(int pre,int l,int r,int ql,int qr,int w){
	ql=max(ql,l); qr=min(qr,r);
	int x=++len; ls[x]=ls[pre];rs[x]=rs[pre];s[x]=s[pre]+w*(qr-ql+1);ad[x]=ad[pre];
	if (ql<=l&&r<=qr) return ad[x]+=w,x;
	int mid=l+r>>1;
	if (ql<=mid) ls[x]=ist(ls[pre],l,mid,ql,qr,w);
	if (qr>mid) rs[x]=ist(rs[pre],mid+1,r,ql,qr,w);
	return x;
}
ll qry(int x,int l,int r,int ql,int qr){
	ql=max(ql,l); qr=min(qr,r);
	if (!x) return 0;
	if (ql<=l&&r<=qr) return s[x];
	int mid=l+r>>1; ll res=ad[x]*(qr-ql+1);
	if (ql<=mid) res+=qry(ls[x],l,mid,ql,qr);
	if (qr>mid) res+=qry(rs[x],mid+1,r,ql,qr);
	return res;
}

int L[maxn],R[maxn],stk[maxn],top;
struct data{
	int l,r,w;
	data () {}
	data (int _l,int _r,int _w):l(_l),r(_r),w(_w) {}
};
vector<data> lv[maxn],rv[maxn];
int main(){
	scanf("%d%d%d%d",&n,&q,&w1,&w2);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	stk[top=0]=0;
	for (int i=1;i<=n;i++){
		while (top&&a[stk[top]]<a[i]) top--;
		L[i]=stk[top]; stk[++top]=i;
	}
	stk[top=0]=n+1;
	for (int i=n;i>=1;i--){
		while (top&&a[stk[top]]<a[i]) top--;
		R[i]=stk[top]; stk[++top]=i;
	}
	for (int i=1;i<=n;i++){
		if (L[i]+1<=i-1&&R[i]<=n) lv[R[i]].push_back(data(L[i]+1,i-1,w2));
		if (i+1<=R[i]-1&&L[i]>=1) rv[L[i]].push_back(data(i+1,R[i]-1,w2));
		if (1<=L[i]&&R[i]<=n) lv[R[i]].push_back(data(L[i],L[i],w1));
	}
	for (int i=1;i<=n;i++){
		Lrot[i]=Lrot[i-1]; Rrot[i]=Rrot[i-1];
		for (int j=0;j<lv[i].size();j++)
		 Lrot[i]=ist(Lrot[i],1,n,lv[i][j].l,lv[i][j].r,lv[i][j].w);
		for (int j=0;j<rv[i].size();j++)
		 Rrot[i]=ist(Rrot[i],1,n,rv[i][j].l,rv[i][j].r,rv[i][j].w);
	}
	
	while (q--){
		int x,y;scanf("%d%d",&x,&y);
		printf("%lld\n",(y-x)*w1+qry(Rrot[y],1,n,x,y)-qry(Rrot[x-1],1,n,x,y)+qry(Lrot[y],1,n,x,y)-qry(Lrot[x-1],1,n,x,y));
	}
	return 0;
}
