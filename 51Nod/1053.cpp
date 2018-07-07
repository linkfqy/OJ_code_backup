#include<cstdio>
#include<algorithm>
#include<queue>
#define _abs(x) ((x)>0?(x):-(x))
using namespace std;
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

const int maxn=50005;
int n,N,m,a[maxn],lst[maxn],nxt[maxn],tot;
ll ans,b[maxn];
inline void del(int i){
	lst[nxt[i]]=lst[i];
	nxt[lst[i]]=nxt[i];
}
struct data{
	ll x;int id;
	data () {}
	data(ll _x,int _id):x(_x),id(_id) {}
	bool operator<(const data&b)const{
		return x>b.x;
	}
};
priority_queue<data> Q;
int main(){
	n=red(),m=red();
	for (int i=1;i<=n;i++){
		a[i]=red();
		if (i==1||(a[i]>0)^(a[i-1]>0)) N++;
		b[N]+=a[i];
	}
	for (int i=1;i<=N;i++){
		lst[i]=i-1;nxt[i]=i+1;
		Q.push(data(_abs(b[i]),i));
		if (b[i]>0) ans+=b[i],tot++;
	}
	lst[0]=0;nxt[0]=1;lst[N+1]=N;nxt[N+1]=N+1;
	while (tot>m){
		data d=Q.top();Q.pop();
		if (lst[nxt[d.id]]!=d.id||nxt[lst[d.id]]!=d.id) continue;
		if (b[d.id]<=0&&(lst[d.id]<1||nxt[d.id]>N)) continue;
		ans-=d.x;tot--;b[d.id]+=b[lst[d.id]]+b[nxt[d.id]];del(lst[d.id]);del(nxt[d.id]);
		Q.push(data(_abs(b[d.id]),d.id));
	}
	printf("%lld",ans);
	return 0;
}
