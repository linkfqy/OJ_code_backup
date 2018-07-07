#include<cstdio>
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

const int maxn=4005;
int n,N,m,mm,b[maxn],wall[maxn],ans;
struct data{
	int l,r;
}a[maxn];
bool vis[maxn];
inline int ID(int x) {return lower_bound(b+1,b+1+m,x)-b;}
int main(){
	N=red();n=red();
	for (int i=1;i<=n;i++) b[++m]=a[i].l=red(),b[++m]=a[i].r=red();
	sort(b+1,b+1+m);mm=m;
	for (int i=1;i<m;i++) if (b[i+1]-b[i]>1) b[++mm]=b[i]+1;
	sort(b+1,b+1+mm);
	m=unique(b+1,b+1+mm)-b-1;
	for (int i=1;i<=n;i++){
		int s=ID(a[i].l),t=ID(a[i].r);
		for (int j=s;j<=t;j++) wall[j]=i;
	}
	for (int i=1;i<=m;i++) vis[wall[i]]=1;
	for (int i=1;i<=n;i++) ans+=vis[i];
	printf("%d",ans);
	return 0;
}
