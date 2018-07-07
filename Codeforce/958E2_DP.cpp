#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
using namespace std;

const int N=500005;
struct note{
	int w,wz;
	bool operator < (const note lyf) const {return w<lyf.w;}
}q[N];
int k,n,a[N],d[N],b[N],f[4][N],p;

inline char nc(void){
	static char ch[100010],*p1=ch,*p2=ch;
	return p1==p2&&(p2=(p1=ch)+fread(ch,1,100010,stdin),p1==p2)?EOF:*p1++;
}

inline void read(int &a){
	static char c=nc();int f=1;
	for (;!isdigit(c);c=nc()) if (c=='-') f=-1;
	for (a=0;isdigit(c);a=(a<<3)+(a<<1)+c-'0',c=nc());
	return (void)(a*=f);
}

int main(){
	read(k),read(n);
	for (int i=1; i<=n; ++i) read(a[i]);
	sort(a+1,a+1+n);
	for (int i=1; i<n; ++i) d[i]=q[i].w=a[i+1]-a[i],q[i].wz=i;
	sort(q+1,q+n);
	for (int i=1; i<=min(n,3*k); ++i) b[q[i].wz]=1;
	memset(f,0x3f,sizeof f);
	for (int i=0; i<=3; ++i) f[i][0]=0;
	for (int i=1; i<=n; ++i)
		if (b[i]){
			++p;
			for (int j=1; j<=min(p,k); ++j)
				f[p&3][j]=min(f[(p-1)&3][j],f[(p-1-b[i-1])&3][j-1]+d[i]);
		}
	return printf("%d\n",f[p&3][k]),0;
}
