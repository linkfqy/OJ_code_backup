#include<cstdio>

const int maxn=100005,maxs=2000005;
int n,e,q,a[maxn],p[maxn],fa[maxn]; char s[5];
inline int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int Rot[maxn],len,tre[maxs],ls[maxs],rs[maxs];
inline void pushup(int x) {tre[x]=tre[ls[x]]+tre[rs[x]];}
inline int newnode(int _ls,int _rs,int _s) {ls[++len]=_ls,rs[len]=_rs,tre[len]=_s;return len;}
void ist(int &x,int l,int r,int k){
	if (!x) x=newnode(0,0,0);
	if (l==r) {tre[x]++;return;}
	int mid=l+r>>1;
	if (k<=mid) ist(ls[x],l,mid,k);
	 else ist(rs[x],mid+1,r,k);
	pushup(x);
}
int qry(int x,int l,int r,int k){
	if (k>tre[x]) return -1;
	if (l==r) return p[l];
	int mid=l+r>>1;
	if (k<=tre[ls[x]]) return qry(ls[x],l,mid,k);
	 else return qry(rs[x],mid+1,r,k-tre[ls[x]]);
}
int merge(int x,int y){
	if (!x||!y) return x+y;
	ls[x]=merge(ls[x],ls[y]);
	rs[x]=merge(rs[x],rs[y]);
	tre[x]=tre[x]+tre[y];
	return x;
}
int main(){
	scanf("%d%d",&n,&e);
	for (int i=1,x;i<=n;i++) scanf("%d",&x),p[x]=i,a[i]=x,fa[i]=i;
	for (int i=1,x,y;i<=e;i++){
		scanf("%d%d",&x,&y);fa[getfa(x)]=getfa(y);
	}
	for (int i=1;i<=n;i++) ist(Rot[getfa(i)],1,n,a[i]);
	scanf("%d",&q);
	while (q--){
		scanf("%s",s);
		if (s[0]=='Q'){
			int x,k;scanf("%d%d",&x,&k);
			printf("%d\n",qry(Rot[getfa(x)],1,n,k));
		}else{
			int x,y;scanf("%d%d",&x,&y);
			if (getfa(x)!=getfa(y)) Rot[getfa(x)]=merge(Rot[getfa(x)],Rot[getfa(y)]),fa[getfa(y)]=getfa(x);
		}
	}
}
