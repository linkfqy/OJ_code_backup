#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
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
int n,q,h[maxn]; ll a[maxn];
struct data{
	int l,r,id;
	bool operator<(const data&b)const{
		if (h[l]==h[b.l]) return r<b.r;
		return l<b.l;
	}
}Q[maxn];
void blocker(){
	int k=sqrt(n);
	for (int i=1;i<=n;i++) h[i]=(i-1)/k+1;
}
int stk[maxn],top,f[maxn][18],log_2[maxn];
ll fl[maxn],fr[maxn];
int Min(int i,int j) {return a[i]<a[j]?i:j;}
void DP(){
	top=0;
	for (int i=1;i<=n;i++){
		while (top&&a[stk[top]]>=a[i]) top--;
		fr[i]=fr[stk[top]]+a[i]*(i-stk[top]);
		stk[++top]=i;
	}
	top=0;stk[0]=n+1;
	for (int i=n;i>=1;i--){
		while (top&&a[stk[top]]>=a[i]) top--;
		fl[i]=fl[stk[top]]+a[i]*(stk[top]-i);
		stk[++top]=i;
	}
	log_2[1]=0;
	for (int i=2;i<=n;i++) log_2[i]=log_2[i>>1]+1;
	for (int i=1;i<=n;i++) f[i][0]=i;
	for (int j=1;j<=log_2[n];j++)
	 for (int i=1;i+(1<<j)-1<=n;i++)
	  f[i][j]=Min(f[i][j-1],f[i+(1<<j-1)][j-1]);
}
int qry(int l,int r){
	int j=log_2[r-l+1];
	return Min(f[l][j],f[r-(1<<j)+1][j]);
}
ll ANS[maxn];
ll istl(int l,int r){
	int p=qry(l,r);
	return a[p]*(r-p+1)+fl[l]-fl[p];
}
ll istr(int l,int r){
	int p=qry(l,r);
	return a[p]*(p-l+1)+fr[r]-fr[p];
}
int main(){
	n=red(),q=red();
	for (int i=1;i<=n;i++) a[i]=red();
	for (int i=1;i<=q;i++) Q[i].l=red(),Q[i].r=red(),Q[i].id=i;
	blocker(); sort(Q+1,Q+1+q);
	DP();
	int L=1,R=0;ll ans=0;
	for (int i=1;i<=q;i++){
		while (Q[i].r>R) ans+=istr(L,++R);
		while (Q[i].r<R) ans-=istr(L,R--);
		while (Q[i].l<L) ans+=istl(--L,R);
		while (Q[i].l>L) ans-=istl(L++,R);
		ANS[Q[i].id]=ans;
	}
	for (int i=1;i<=q;i++) printf("%lld\n",ANS[i]);
	return 0;
}
