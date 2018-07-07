#include<cstdio>
typedef long long ll;
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

const int maxn=100005,maxe=200005,tt=1000000007;
int n,c[maxn];
int tot,lnk[maxn],nxt[maxe],son[maxe];
ll f[maxn][2];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
void dfs(int x,int fa){
	f[x][c[x]]=1;
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa){
	 	dfs(son[j],x);
	 	f[x][1]=(f[x][1]*(f[son[j]][0]+f[son[j]][1])%tt+f[x][0]*f[son[j]][1])%tt;
	 	(f[x][0]*=f[son[j]][0]+f[son[j]][1])%=tt;
	 }
}
int main(){
	n=red();
	for (int i=1,x,y;i<n;i++) x=red()+1,y=i+1,add(x,y),add(y,x);
	for (int i=1;i<=n;i++)
	 c[i]=red();
	dfs(1,0);
	printf("%lld",f[1][1]);
	return 0;
} 
