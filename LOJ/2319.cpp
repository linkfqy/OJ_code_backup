#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
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

const int maxn=300005,maxs=12000005;
int n,m,q,M;
int s[maxs],ls[maxs],rs[maxs],Rot[maxn],len;
inline void pushup(int x) {s[x]=s[ls[x]]+s[rs[x]];}
void ist(int &x,int l,int r,int k){
	if (!x) x=++len;
	if (l==r) return (void)(s[x]=1,x);
	int mid=l+r>>1;
	if (k<=mid) ist(ls[x],l,mid,k);else ist(rs[x],mid+1,r,k);
	pushup(x);
}
int qry(int x,int l,int r,int k){
	if (l==r) return l;
	int mid=l+r>>1,tem=mid-l+1 - s[ls[x]];
	if (k<=tem) return qry(ls[x],l,mid,k);else return qry(rs[x],mid+1,r,k-tem);
}
vector<ll> V[maxn];
ll work0(int x,ll w){
	int p=qry(Rot[0],1,M,x); ist(Rot[0],1,M,p);
	ll res=(p<=n)?(ll)p*m:V[0][p-n-1];
	V[0].push_back(w?w:res);
	return res;
}
ll work1(int x,int y){
	int p=qry(Rot[x],1,M,y); ist(Rot[x],1,M,p);
	ll res=(p<m)?((ll)x-1)*m+p:V[x][p-m];
	V[x].push_back(work0(x,res));
	return res;
}
int main(){
	n=red(),m=red();q=red();M=max(n,m)+q;
	while (q--){
		int x=red(),y=red();
		printf("%lld\n",y==m?work0(x,0):work1(x,y));
	}
	return 0;
}
