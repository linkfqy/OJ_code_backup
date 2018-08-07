#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
typedef long long ll;
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

const int maxn=100005;
const double PI=acos(-1);
int tst,n,N,a[maxn],s[maxn],g[maxn];
struct comp{
	double r,i;
	comp (double _r=0,double _i=0):r(_r),i(_i) {}
	comp operator+(const comp&b) {return comp(r+b.r,i+b.i);}
	comp operator-(const comp&b) {return comp(r-b.r,i-b.i);}
	comp operator*(const comp&b) {return comp(r*b.r-i*b.i,r*b.i+i*b.r);}
}S[maxn*4],F[maxn*4];
int rev[maxn*4];
inline void get_rev(int n) {for (int i=1,l=log2(n);i<n;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<l-1);}
void FFT(comp *a,int n,int d){
	for (int i=0;i<n;i++) if (rev[i]<i) swap(a[rev[i]],a[i]);
	for (int l=2;l<=n;l<<=1){
		comp wl(cos(2*PI/l),d*sin(2*PI/l)); int tj=l>>1;
		for (int k=0;k<n;k+=l){
			comp w(1,0),_t,_T;
			for (int j=0;j<tj;j++,w=w*wl)
			 _t=a[k+j],_T=w*a[k+j+tj],a[k+j]=_t+_T,a[k+j+tj]=_t-_T;
		}
	}
	if (d<0) for (int i=0;i<n;i++) a[i].r/=n;
}
#define C2(x) ((ll)x*(x-1)/2)
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	tst=red();
	N=1;while (N<=2e5) N<<=1;
	get_rev(N);
	while (tst--){
		n=red();
		cl(S,0);cl(s,0);
		for (int i=1;i<=n;i++) a[i]=red(),s[a[i]]++,S[a[i]].r++;
		for (int i=1e5;i;i--) g[i]=g[i+1]+s[i];
		FFT(S,N,1); for (int i=0;i<N;i++) F[i]=S[i]*S[i];
		FFT(F,N,-1);
		double ans=0;
		for (int i=1;i<=1e5;i++)
		 if (i&1) ans+=(ll)(F[i].r+0.5)/2*g[i];
		 else ans+=(((ll)(F[i].r+0.5)-(ll)s[i/2]*s[i/2])/2+C2(s[i/2]))*g[i];
		printf("%.7lf\n",1-ans*6/n/(n-1)/(n-2));
	}
	return 0;
}
