#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
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

const int maxn=500005;
int n,a[maxn],g[maxn],f[maxn];
void Divide(int ql,int qr,int l,int r){
	if (ql>qr) return;
	int mid=ql+qr>>1,p=0;
	double w=0;
	for (int i=l;i<=mid&&i<=r;i++)
	 if (a[i]+sqrt(mid-i)>w) w=a[i]+sqrt(mid-i),p=i;
	f[mid]=ceil(w);
	Divide(ql,mid-1,l,p);Divide(mid+1,qr,p,r);
}
int main(){
	n=red();
	for (int i=1;i<=n;i++) a[i]=red();
	Divide(1,n,1,n);
	memcpy(g,f,sizeof(f));
	memset(f,0,sizeof(f));
	for (int i=1;i*2<=n;i++) swap(a[i],a[n-i+1]);
	Divide(1,n,1,n);
	for (int i=1;i<=n;i++) printf("%d\n",max(g[i],f[n-i+1])-a[n-i+1]);
	return 0;
}
