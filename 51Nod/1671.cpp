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

const int maxn=500005,INF=0x3f3f3f3f;
int n,q;
struct data{
	int s,t;
	bool operator<(const data&b)const{
		return t-s>b.t-b.s;
	}
}a[maxn];
bool check(int s){
	int l1=-INF,r1=INF,l2=-INF,r2=INF;
	for (int i=1;i<=q;i++){
		if (a[i].t-a[i].s<=s) continue;
		l1=max(l1,a[i].s+a[i].t-s);
		r1=min(r1,a[i].s+a[i].t+s);
		l2=max(l2,a[i].s-a[i].t-s);
		r2=min(r2,a[i].s-a[i].t+s);
		if (l1>r1) return 0;
		if (l2>r2) return 0;
	}
	return 1; 
}
int main(){
	n=red(),q=red();
	for (int i=1;i<=q;i++){
		a[i].s=red(),a[i].t=red();
		if (a[i].s>a[i].t) swap(a[i].s,a[i].t);
	}
	int L=0,R=n,ans=n;
	while (L<=R){
		int mid=L+R>>1;
		if (check(mid)) ans=mid,R=mid-1;else L=mid+1;
	}
	printf("%d",ans);
	return 0;
} 
