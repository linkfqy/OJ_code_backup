#include<cstdio>

const int maxn=100005,maxs=400005;
int n,q; char str[maxn];
int s[26][maxs],cv[26][maxs];
inline void pushup(int x,int t) {s[t][x]=s[t][x<<1]+s[t][x<<1|1];}
void build(int x,int l,int r,int t) {
	cv[t][x]=-1;
	if (l==r) {s[t][x]=(str[l]>=t);return;}
	int mid=l+r>>1;
	build(x<<1,l,mid,t);build(x<<1|1,mid+1,r,t);
	pushup(x,t);
}
inline void addcv(int x,int l,int r,int w,int t) {s[t][x]=w*(r-l+1),cv[t][x]=w;}
inline void pushdown(int x,int l,int mid,int r,int t){
	if (cv[t][x]>=0)
	 addcv(x<<1,l,mid,cv[t][x],t),addcv(x<<1|1,mid+1,r,cv[t][x],t),cv[t][x]=-1;
}
void ist(int x,int l,int r,int ql,int qr,int w,int t){
	if (ql<=l&&r<=qr) {addcv(x,l,r,w,t);return;}
	if (qr<l||r<ql) return;
	int mid=l+r>>1; pushdown(x,l,mid,r,t);
	ist(x<<1,l,mid,ql,qr,w,t);ist(x<<1|1,mid+1,r,ql,qr,w,t);
	pushup(x,t);
}
int qry(int x,int l,int r,int ql,int qr,int t){
	if (ql<=l&&r<=qr) return s[t][x];
	if (qr<l||r<ql) return 0;
	int mid=l+r>>1; pushdown(x,l,mid,r,t);
	return qry(x<<1,l,mid,ql,qr,t)+qry(x<<1|1,mid+1,r,ql,qr,t);
}
int main(){
	scanf("%d%d%s",&n,&q,str+1);
	for (int i=1;i<=n;i++) str[i]-='a';
	for (int i=0;i<26;i++) build(1,1,n,i);
	while (q--){
		int l,r,c;scanf("%d%d%d",&l,&r,&c);
		for (int i=0;i<26;i++){
			int w=qry(1,1,n,l,r,i);
			if (c) ist(1,1,n,l,r-w,0,i),ist(1,1,n,r-w+1,r,1,i);
			else ist(1,1,n,l,l+w-1,1,i),ist(1,1,n,l+w,r,0,i);
		}
	}
	for (int i=0;i<26;i++){
		for (int j=1;j<=n;j++) printf("%d ",qry(1,1,n,j,j,i));
		putchar('\n');
	}
	for (int i=1;i<=n;i++)
	 for (int j=0;j<26;j++)
	  if (!qry(1,1,n,i,i,j)){
	  	putchar(j-1+'a');break;
	  }else if (j==25) putchar('z');
	return 0;
}
