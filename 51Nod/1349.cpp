#include<cstdio>
typedef long long ll;
inline char nc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int red(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=(res<<3)+(res<<1)+ch-48,ch=nc();
	return res*f;
}

const int maxn=100005;
int n,q,a[maxn],stk[maxn],len,l[maxn],r[maxn];
ll s[maxn];
int main(){
	n=red();
	for (int i=1;i<=n;i++) a[i]=red();
	len=0;stk[0]=0;
	for (int i=1;i<=n;i++){
		while (len&&a[stk[len]]<=a[i]) len--;
		l[i]=stk[len];stk[++len]=i;
	}
	len=0;stk[0]=n+1;
	for (int i=n;i;i--){
		while (len&&a[stk[len]]<a[i]) len--;
		r[i]=stk[len];stk[++len]=i;
	}
	for (int i=1;i<=n;i++) s[a[i]]+=(ll)(i-l[i])*(r[i]-i);
	for (int i=1;i<=100000;i++) s[i]+=s[i-1];
	q=red();ll sum=(ll)n*(n+1)/2;
	while (q--){
		int x=red();
		printf("%lld\n",sum-s[x-1]);
	}
	return 0;
} 
