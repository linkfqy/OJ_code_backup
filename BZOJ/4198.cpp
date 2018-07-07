#include<cstdio>
#include<queue>
#include<algorithm>
#define LL long long 
using namespace std;
inline char nc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline LL red(){
	LL res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
	return res*f;
}

const int maxn=100105;
int n,k;
struct data{
	LL w,dep,ans;
	data() {}
	data(LL a,LL b):w(a),dep(b),ans(0) {}
	bool operator<(const data&b)const{
		return w>b.w||w==b.w&&dep>b.dep;
	}
}a[15];
priority_queue<data> Q;
int main(){
	n=red(),k=red();
	for (int i=1;i<=n;i++) Q.push(data(red(),0));
	while ((n-1)%(k-1)!=0) Q.push(data(0,0)),n++;
	while (Q.size()>1){
		data x(0,0);
		for (int i=1;i<=k;i++)
		 a[i]=Q.top(),Q.pop(),
		 x.w+=a[i].w,x.dep=max(a[i].dep+1,x.dep),x.ans+=a[i].ans+a[i].w;
		Q.push(x);
	}
	printf("%lld\n%lld",Q.top().ans,Q.top().dep);
	return 0;
} 
