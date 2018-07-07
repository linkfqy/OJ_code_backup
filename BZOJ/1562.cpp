#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=20005,maxe=20005;
int n,res;
int tot,son[maxe],nxt[maxe],lnk[maxn];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
int con[maxn],vis[maxn],Tim=0,ans[maxn];
//bool find(int x){
//	if (vis[x]==Tim) return 0;
//	vis[x]=Tim;
//	for (int j=lnk[x];j;j=nxt[j]){
//		int k=con[son[j]];con[son[j]]=x;
//		if (k==-1||find(k)) return 1;
//		con[son[x]]=k;
//	}
//	return 0;
//}
bool find(int x){
	for (int j=lnk[x];j;j=nxt[j])
	 if (vis[son[j]]!=Tim){
	 	vis[son[j]]=Tim;
	 	if (con[son[j]]==-1||find(con[son[j]])) return con[son[j]]=x,1;
	 }
	return 0;
} 
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		int d;scanf("%d",&d);
		int a=(i+d)%n+n,b=(i-d+n)%n+n;
		if (a<b) swap(a,b);
		add(i,a);add(i,b);
	}
	memset(con,255,sizeof(con));
	for (int i=n-1;i>=0;i--)
	 Tim++,res+=find(i);
	for (int i=n;i<2*n;i++) ans[con[i]]=i-n;
	if (res!=n) return printf("No Answer"),0;
	printf("%d",ans[0]);
	for (int i=1;i<n;i++) printf(" %d",ans[i]);
	return 0;
} 
