#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=50005;
const double eps=1e-7;
int n,m;
struct data{
	int k,b,id;
	bool operator<(const data&y)const{
		return k<y.k||k==y.k&&b>y.b;
	}
	double getx(data y){
		return (double)(y.b-b)/(k-y.k);
	}
}a[maxn],que[maxn];
int dcmp(double x){
	if (fabs(x)<=eps) return 0;
	return x>0?1:-1;
}
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
bool cmp(const data&a,const data&b){
	return a.id<b.id;
}
int main(){
	n=red();
	for (int i=1;i<=n;i++) a[i].k=red(),a[i].b=red(),a[i].id=i;
	sort(a+1,a+1+n);
	m=1;
	for (int i=2;i<=n;i++)
	 if (a[i-1].k<a[i].k) a[++m]=a[i];
	int len=0;
	for (int i=1;i<=m;i++){
		while (len>1&&dcmp(que[len-1].getx(que[len])-que[len-1].getx(a[i]))>=0) len--;
		que[++len]=a[i];
	}
	sort(que+1,que+1+len,cmp);
	for (int i=1;i<=len;i++) printf("%d ",que[i].id);
	return 0;
}
