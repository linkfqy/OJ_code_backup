#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;

const int maxn=100005;
int tst,n,e,f[maxn],ans[maxn];
int tot,nxt[maxn],son[maxn],lnk[maxn];
priority_queue<int> Q;
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
int main(){
	scanf("%d",&tst);
	while (tst--){
		scanf("%d%d",&n,&e);
		while (!Q.empty()) Q.pop();
		cl(lnk,0);tot=0;cl(f,0);
		for (int i=1,x,y;i<=e;i++)
		 scanf("%d%d",&x,&y),add(y,x),f[x]++;
		for (int i=1;i<=n;i++)
		 if (!f[i]) Q.push(i);
		ans[0]=0;
		while (!Q.empty()){
			int x=Q.top();Q.pop();ans[++ans[0]]=x;
			for (int j=lnk[x];j;j=nxt[j]){
				f[son[j]]--;
				if (!f[son[j]]) Q.push(son[j]);
			}
		}
		if (ans[0]<n) printf("Impossible!");else
		 for (int i=ans[0];i;i--) printf("%d ",ans[i]);
		putchar('\n');
	}
	return 0;
}
