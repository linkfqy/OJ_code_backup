#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;

const int maxn=100005,maxe=maxn;
int tst,n,fa[maxn];
int tot,son[maxe],nxt[maxe],lnk[maxn],w[maxn];
inline void add(int x,int y,int z){
    son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=z;
}
char s[20];
int stk[maxn],dfn[maxn],low[maxn],times,SCC,to[maxn],sum[maxn],who[maxn],num[maxn];
bool instk[maxn];
void Tarjan(int x){
    dfn[x]=low[x]=++times; instk[stk[++stk[0]]=x]=1;
    for (int j=lnk[x];j;j=nxt[j])
     if (!dfn[son[j]]) Tarjan(son[j]),low[x]=min(low[x],low[son[j]]);
     else if (instk[son[j]]) low[x]=min(low[x],dfn[son[j]]);
    if (low[x]==dfn[x]){
        SCC++;
        while (stk[stk[0]+1]!=x)
         to[stk[stk[0]]]=SCC,instk[stk[stk[0]--]]=0;
    }
}
inline int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int main(){
    scanf("%d",&tst);
    while (tst--){
        scanf("%d",&n); tot=0;cl(lnk,0);
        for (int i=1,x;i<=n;i++) scanf("%d%s",&x,s),add(i,x,s[0]=='w');
        cl(dfn,0);cl(instk,0);times=SCC=0;stk[0]=0;
        for (int i=1;i<=n;i++) if (!dfn[i]) Tarjan(i);
        cl(sum,0); cl(num,0);
        for (int i=1;i<=n;i++) fa[i]=i;
        for (int i=1;i<=n;i++)
         for (int j=lnk[i];j;j=nxt[j])
          if (to[i]==to[son[j]]&&w[j]==1) sum[to[i]]++,who[to[i]]=son[j];else
          if (to[i]!=to[son[j]]&&w[j]==0) fa[getfa(i)]=getfa(son[j]);
        for (int i=1;i<=n;i++) num[getfa(i)]++;
        int ans=0;
        for (int i=1;i<=SCC;i++)
         if (sum[i]==1) ans+=num[who[i]];
        printf("0 %d\n",ans);
    }
    return 0;
}
