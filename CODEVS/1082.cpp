#include<cstdio>
#define LL long long
#define lowbit(x) ((x)&-(x))
const int maxn=200005;
int n,q;
LL c[maxn],cc[maxn];
inline int red(){
	int tot=0,f=1;char ch=getchar();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=getchar();}
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot*f;
}
void add(LL *tre,int x,LL w){
	for (int i=x;i<=n;i+=lowbit(i)) tre[i]+=w;
}
LL qry(LL *tre,int x){
	LL res=0;
	for (int i=x;i;i-=lowbit(i)) res+=tre[i];
	return res;
}
LL getsum(int x){return qry(c,x)*x-qry(cc,x);}
int main(){
	n=red();
	for (int i=1;i<=n;i++){
		LL x=red();
		add(c,i,x),add(c,i+1,-x),add(cc,i,x*(i-1)),add(cc,i+1,-x*i);
	}
	q=red();
	while (q--)
	 if (red()==1){
	 	int l=red(),r=red();LL w=red();
	 	add(c,l,w),add(c,r+1,-w);add(cc,l,w*(l-1)),add(cc,r+1,-w*r);
	 }else{
	 	int l=red(),r=red();
	 	printf("%lld\n",getsum(r)-getsum(l-1));
	 }
	return 0;
}
