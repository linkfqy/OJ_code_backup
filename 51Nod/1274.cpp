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

const int maxn=50005;
int n,e,f[maxn];
struct edge{
	int x,y,w;
	bool operator<(const edge&b)const{
		return w<b.w;
	}
}a[maxn];
struct data{
	int x,i;
	data () {}
	data (int _i,int _x):i(_i),x(_x) {}
}q[maxn];
int main(){
	n=red(),e=red();
	for (int i=1;i<=e;i++) a[i].x=red()+1,a[i].y=red()+1,a[i].w=red();
	sort(a+1,a+1+e);
	
	for (int i=1;i<=e;){
		int j=i,len=0;
		while (j<=e&&a[j].w==a[i].w){
			q[++len]=data(a[j].x,f[a[j].y]+1);
			q[++len]=data(a[j].y,f[a[j].x]+1);
			j++;
		}
		i=j;
		for (j=1;j<=len;j++) f[q[j].i]=max(f[q[j].i],q[j].x);
	}
	int ans=0;
	for (int i=1;i<=n;i++) ans=max(ans,f[i]);
	printf("%d",ans);
	return 0;
}
