#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef unsigned long long ull;
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

const int maxn=55,maxe=105;
const ull p[55]={51,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317};
int N,n[maxn],id[maxn];
int tot,son[maxe],lnk[maxn],nxt[maxe];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
ull hash[maxn],table[maxn][maxn];
bool cmp(int i,int j){
	return hash[i]<hash[j];
}
void dfs(int x,int fa){
	hash[x]=p[0];
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa) dfs(son[j],x);
	id[0]=0;
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa) id[++id[0]]=son[j];
	sort(id+1,id+1+id[0],cmp);
	for (int i=1;i<=id[0];i++) hash[x]+=hash[id[i]]*p[i];
}
int main(){
	N=red();
	for (int i=1;i<=N;i++){
		n[i]=red();cl(lnk,0);tot=0;
		for (int j=1;j<=n[i];j++){
			int fa=red();
			if (fa!=0) add(fa,j),add(j,fa);
		}
		for (int j=1;j<=n[i];j++)
		 dfs(j,0),table[i][j]=hash[j];
		sort(table[i]+1,table[i]+1+n[i]);
	}
	for (int i=1;i<=N;i++){
		for (int j=1;j<=N;j++)
		if (n[i]==n[j]){
			int suc=1;
			for (int k=1;k<=n[i];k++)
			 if (table[i][k]!=table[j][k]) {suc=0;break;}
			if (suc) {printf("%d\n",j);break;}
		}
	}
	return 0;
}
