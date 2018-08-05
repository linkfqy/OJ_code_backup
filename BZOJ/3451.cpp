#include<cstdio>
#include<cmath>
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

const int maxn=100005;
const double PI=3.1415926535897932384626433832795;
int n; double S[maxn];
int tot,lnk[maxn],son[maxn],nxt[maxn];
inline void add(int x,int y) {son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;}
struct comp{
	double r,i;
	comp (double _r=0,double _i=0):r(_r),i(_i) {}
	comp operator + (const comp&b) {return comp(r+b.r,i+b.i);}
	comp operator - (const comp&b) {return comp(r-b.r,i-b.i);}
	comp operator * (const comp&b) {return comp(r*b.r-i*b.i,r*b.i+i*b.r);}
	comp operator / (const double&b) {return comp(r/b,i/b);} 
}A[262145];
int rev[262145];
void get_rev(int n){
	rev[0]=0;int l=log2(n);
	for (int i=1;i<n;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<l-1);
}
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
	if (d<0) for (int i=0;i<n;i++) a[i]=a[i]/n;
}

int rot,sum,siz[maxn],f[maxn],dep[maxn],val[maxn];
bool vis[maxn];
void calc(int Miu){
	int mx=0,n=1;
	for (int i=1;i<=tot;i++) mx=max(mx,val[i]);
	while (n<=(mx<<1)) n<<=1;get_rev(n);
	for (int i=0;i<n;i++) A[i]=(0,0);
	for (int i=1;i<=tot;i++) A[val[i]].r++;
	FFT(A,n,1);
	for (int i=0;i<n;i++) A[i]=A[i]*A[i];
	FFT(A,n,-1);
	for (int i=0;i<=mx<<1;i++) S[i]+=Miu*A[i].r;
}
void getrot(int x,int fa){
	siz[x]=1;f[x]=0;
	for (int j=lnk[x];j;j=nxt[j]){
		if (vis[son[j]]||son[j]==fa) continue;
		getrot(son[j],x);
		siz[x]+=siz[son[j]];
		f[x]=max(f[x],siz[son[j]]);
	}
	f[x]=max(f[x],sum-siz[x]);
	if (f[x]<f[rot]) rot=x;
}
void dfs(int x,int fa){
	val[++tot]=dep[x];siz[x]=1;
	for (int j=lnk[x];j;j=nxt[j])
	 if (!vis[son[j]]&&son[j]!=fa)
	  dep[son[j]]=dep[x]+1,dfs(son[j],x),siz[x]+=siz[son[j]];
}
void solve(int x){
	dep[x]=tot=0;dfs(x,0);calc(1);vis[x]=1;
	for (int j=lnk[x];j;j=nxt[j])
	 if (!vis[son[j]]){
		rot=0; sum=siz[son[j]];
		dep[son[j]]=1; tot=0;
		dfs(son[j],0); calc(-1);
		sum=siz[son[j]]; rot=0;
		getrot(son[j],0); solve(rot);
	 }
}
int main()
{
	n=red();
	for (int i=1,x,y,z;i<n;i++) x=red()+1,y=red()+1,add(x,y),add(y,x);
	dep[0]=-1; f[0]=2e9; sum=n;
	getrot(1,0); solve(rot);
	double ans=0;
	for (int i=0;i<n;i++) ans+=S[i]/(i+1);
	printf("%.4lf\n",ans);
	return 0;
}
