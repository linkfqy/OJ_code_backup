#include<cstdio>
#include<cctype>
using namespace std;
const int maxn=16;

int te,ans;char s[maxn+5][maxn+5],now[5][5];
int ti,vis[maxn+5];

inline void Rotate(int A,int B){
    for (int i=A;i<=A+3;i++)
        for (int j=B;j<=B+3;j++)
            now[i-A][j-B]=s[i][j];
    for (int i=A;i<=A+3;i++)
        for (int j=B;j<=B+3;j++)
            s[i][j]=now[3-j+B][i-A];
}
#define ID(x) (isdigit(x)?x-'0':x-'A'+10)
inline bool check(int r){
    for (int j=(ti++,1);j<=maxn;j++){
        if (vis[ID(s[r][j])]==ti) return false;
        vis[ID(s[r][j])]=ti;
    }
    return true;
}
inline bool check(){
    for (int j=(ti++,1);j<=maxn;j++,ti++)
        for (int i=1;i<=maxn;i++){
            if (vis[ID(s[i][j])]==ti) return false;
            vis[ID(s[i][j])]=ti;
        }
    return true;
}
void Dfs(int x,int now=0){
    if (now>=ans) return;int X=x/4*4+1,Y=x%4*4+1;
    for (int i=1;i<X;i++) if (!check(i)) return;
    if (x==maxn) {if (check()) ans=now;return;}
    Dfs(x+1,now);
    Rotate(X,Y);Dfs(x+1,now+1);
    Rotate(X,Y);Dfs(x+1,now+2);
    Rotate(X,Y);Dfs(x+1,now+3);
    Rotate(X,Y);
}
int main(){
    for (scanf("%d",&te);te;te--){
        for (int i=1;i<=maxn;i++) scanf("%s",s[i]+1);
        ans=2e9;Dfs(0);printf("%d\n",ans);
    }
    return 0;
}
