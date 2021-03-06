#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=20005,maxe=2*maxn;
int n,hvy,S,ans;
int tot,son[maxe],nxt[maxe],lnk[maxn],w[maxe];
int MAX[maxn],siz[maxn],dep[maxn],num[3];
bool vis[maxn];
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
void add(int x,int y,int z){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=z;
}
int gcd(int x,int y){
	return !y?x:gcd(y,x%y);
}
void get_hvy(int x,int fa){
	MAX[x]=0;siz[x]=1;
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa&&!vis[son[j]]){
	 	get_hvy(son[j],x);
	 	siz[x]+=siz[son[j]];
	 	MAX[x]=max(MAX[x],siz[son[j]]);
	 }
	MAX[x]=max(MAX[x],S-siz[x]);
	if (!hvy||MAX[x]<MAX[hvy]) hvy=x;
}
void get_dep(int x,int fa){
	num[dep[x]%3]++;
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa&&!vis[son[j]])
	  dep[son[j]]=dep[x]+w[j],get_dep(son[j],x);
}
int get_sum(int x,int dst){
	num[0]=num[1]=num[2]=0;
	dep[x]=dst;get_dep(x,0);
	return num[0]*num[0]+num[1]*num[2]*2;
}
void get_ans(int x){
	vis[x]=1;ans+=get_sum(x,0);
	for(int j=lnk[x];j;j=nxt[j])
	 if (!vis[son[j]]){
	 	ans-=get_sum(son[j],w[j]);
	 	hvy=0;S=siz[son[j]];get_hvy(son[j],0);
	 	get_ans(hvy);
	 }
}
int main(){
	n=red();
	for (int i=1,x,y,z;i<n;i++)
	 x=red(),y=red(),z=red(),add(x,y,z),add(y,x,z);
	hvy=0;S=n;get_hvy(1,0);
	ans=0;get_ans(hvy);int x=n*n;
	int t=gcd(ans,x);
	ans/=t;x/=t;
	printf("%d/%d",ans,x);
	return 0;
} 
