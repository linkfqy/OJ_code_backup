#include<cstdio>
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

const int maxn=100005,maxe=200005;
int n,c[maxn],cnt[maxn],num[maxn]; ll sum[maxn],ans[maxn];
int tot,son[maxe],nxt[maxe],lnk[maxn];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
int H_son[maxn],s[maxn],MAX;
bool xH[maxn];
void getH(int x,int fa){
	s[x]=1;H_son[x]=0;
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa){
	 	getH(son[j],x); s[x]+=s[son[j]];
	 	if (!H_son[x]||s[H_son[x]]<s[son[j]]) H_son[x]=son[j];
	 }
}
void change(int x,int fa,int w){
	num[cnt[c[x]]]--; sum[cnt[c[x]]]-=c[x];
	cnt[c[x]]+=w;
	num[cnt[c[x]]]++; sum[cnt[c[x]]]+=c[x];
	if (num[MAX+1]) MAX++;else if (!num[MAX]) MAX--;
	
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa&&!xH[son[j]]) change(son[j],x,w);
}
void dsu(int x,int fa,bool keep){
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa&&son[j]!=H_son[x]) dsu(son[j],x,0);
	if (H_son[x]) dsu(H_son[x],x,1),xH[H_son[x]]=1;
	change(x,fa,1); xH[H_son[x]]=0;
	ans[x]=sum[MAX];
	if (!keep) change(x,fa,-1);
}
int main(){
	n=red();
	for (int i=1;i<=n;i++) c[i]=red();
	for (int i=1,x,y;i<n;i++) x=red(),y=red(),add(x,y),add(y,x);
	getH(1,0);dsu(1,0,0);
	for (int i=1;i<=n;i++) printf("%I64d ",ans[i]);
	return 0;
}
