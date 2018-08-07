#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef long long ll;

const int maxn=400005;
const double PI=3.1415926535897932384626433832795;
int n,N; double q[maxn];
struct comp{
	double r,i;
	comp(double _r=0,double _i=0):r(_r),i(_i) {}
	comp operator+(const comp&b) {return comp(r+b.r,i+b.i);}
	comp operator-(const comp&b) {return comp(r-b.r,i-b.i);}
	comp operator*(const comp&b) {return comp(r*b.r-i*b.i,r*b.i+i*b.r);}
}Q[maxn],G[maxn],C[maxn],D[maxn];
int rev[maxn];
inline void get_rev(int n) {for (int i=1,l=log2(n);i<n;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<l-1);}
void FFT(comp *a,int n,int d){
	for (int i=0;i<n;i++) if (rev[i]<i) swap(a[i],a[rev[i]]);
	for (int l=2;l<=n;l<<=1){
		comp wl(cos(2*PI/l),d*sin(2*PI/l));
		for (int k=0;k<n;k+=l){
			comp w(1,0),_t,_T;
			for (int j=0,tj=l>>1;j<tj;j++,w=w*wl)
			 _t=a[k+j],_T=w*a[k+j+tj],a[k+j]=_t+_T,a[k+j+tj]=_t-_T;
		}
	}
	if (d<0) for (int i=0;i<n;i++) a[i].r/=n;
}
int main(){
	scanf("%d",&n); N=1;while (N<=n) N<<=1;N<<=1;
	for (int i=1;i<=n;i++) scanf("%lf",&q[i]),Q[i].r=q[i],G[i].r=1.0/i/i;
	get_rev(N);
	FFT(Q,N,1);FFT(G,N,1); for (int i=0;i<N;i++) C[i]=Q[i]*G[i];
	cl(Q,0);
	for (int i=0;i<=n;i++) Q[i]=comp(q[n-i],0);
	FFT(Q,N,1); for (int i=0;i<N;i++) D[i]=Q[i]*G[i];
	FFT(C,N,-1); FFT(D,N,-1);
	for (int i=1;i<=n;i++) printf("%.3lf\n",C[i].r-D[n-i].r);
	return 0;
}
