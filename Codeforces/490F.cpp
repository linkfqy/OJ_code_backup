#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=6005,maxe=12005;
int n,w[maxn],ans;
int tot,son[maxe],nxt[maxe],lnk[maxn];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
int que[maxn],til;
void dfs(int x,int fa){
	int pos=-1,old;
	if (!til||que[til]<w[x]) que[++til]=w[x];else{
		pos=lower_bound(que+1,que+1+til,w[x])-que;
		old=que[pos]; que[pos]=w[x];
	}
	ans=max(ans,til);
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=fa) dfs(son[j],x);
	if (pos<0) til--;else que[pos]=old;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	for (int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	for (int i=1;i<=n;i++) til=0,dfs(i,i);
	printf("%d",ans);
	return 0;
}
