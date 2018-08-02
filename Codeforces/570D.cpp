#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
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
inline char fstchar(){
	char ch=nc();while (ch<'a'||'z'<ch) ch=nc();
	return ch;
}

const int maxn=500005,maxe=500005;
int n,q,s[maxn],num[maxn][26];
struct data{
	int dep,id;
	data () {}
	data (int _x,int _y):dep(_x),id(_y) {}
};
bool ans[maxn];
vector<data> V[maxn];
int tot,son[maxe],nxt[maxe],lnk[maxn];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
int dep[maxn],H_son[maxn],wt[maxn];
void getH(int x){
	H_son[x]=0;wt[x]=1;
	for (int j=lnk[x];j;j=nxt[j]){
		dep[son[j]]=dep[x]+1; getH(son[j]); wt[x]+=wt[son[j]];
		if (!H_son[x]||wt[H_son[x]]<wt[son[j]]) H_son[x]=son[j];
	}
}
bool xH[maxn];
void change(int x,int w){
	num[dep[x]][s[x]]+=w;
	for (int j=lnk[x];j;j=nxt[j])
	 if (!xH[son[j]]) change(son[j],w);
}
void dsu(int x,bool keep){
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=H_son[x]) dsu(son[j],0);
	if (H_son[x]) dsu(H_son[x],1),xH[H_son[x]]=1;
	change(x,1); xH[H_son[x]]=0;
	for (int i=0;i<V[x].size();i++){
		int tot=0;
		for (int j=1;j<=26;j++)
		 if (num[V[x][i].dep][j]&1) tot++;
		ans[V[x][i].id]=(tot<=1);
	}
	if (!keep) change(x,-1);
}
int main(){
	n=red();q=red();
	for (int i=2,fa;i<=n;i++) fa=red(),add(fa,i);
	for (int i=1;i<=n;i++) s[i]=fstchar()-'a'+1;
	for (int i=1;i<=q;i++){
		int x=red(),y=red();
		V[x].push_back(data(y,i));
	}
	dep[1]=1;getH(1);dsu(1,0);
	for (int i=1;i<=q;i++) puts(ans[i]?"Yes":"No");
	return 0;
}
