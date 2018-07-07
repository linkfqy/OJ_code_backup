#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;
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
 
const int maxn=2505;
const double eps=1e-5;
int n,K,p[maxn],s[maxn];
int tot,son[maxn],nxt[maxn],lnk[maxn];
inline void add(int x,int y){
    son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
int in[maxn],out[maxn],times,id[maxn];
void dfs(int x){
    in[x]=++times;id[times]=x;
    for (int j=lnk[x];j;j=nxt[j])
     dfs(son[j]);
    out[x]=times;
}
double f[maxn][maxn],ans,mid;
#define w(x) (p[x]-mid*s[x])
bool check(){
    cl(f,250);
    f[0][0]=0;
    for (int i=0;i<=n;i++)
     for (int j=0;j<=K;j++)
      f[i+1][j+1]=max(f[i][j]+w(id[i]),f[i+1][j+1]),
      f[out[id[i]]+1][j]=max(f[i][j],f[out[id[i]]+1][j]);
    return f[n+1][K]>=0;
}
int main(){
    K=red()+1,n=red();
    for (int i=1,fa;i<=n;i++) s[i]=red(),p[i]=red(),fa=red(),add(fa,i);
    times=-1;dfs(0);
    double L=0,R=1e4;
    while (R-L>=eps){
        mid=(L+R)/2;
        if (check()) ans=mid,L=mid;else R=mid;
    }
    printf("%.3lf",ans);
    return 0;
}
