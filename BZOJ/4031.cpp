#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef ll matrix[200][200];
 
const int maxn=15,p[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const ll MD=1e9;
int n,N,m,id[maxn][maxn];
char s[maxn][maxn];
matrix kir;
inline void A(ll &a,ll b){ (a+=(b%MD+MD)%MD)%=MD; }
inline void add(int u,int v){
    A(kir[u][v],-1);A(kir[v][v],1);
}
void mkid(){
    N=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) if (s[i][j]=='.') id[i][j]=++N;
}
ll det(matrix a,int n){
    ll f=1,res=1;
    for (int i=1;i<=n;i++){
        int where=-1;
        for (int j=i;j<=n;j++) if (a[j][i]!=0) {where=j;break;}
        if (where<0) return 0;
		if (where!=i) swap(a[i],a[where]),f=-f;
        for (int j=i+1;j<=n;j++)
			while (a[j][i]!=0){
				ll t=a[j][i]/a[i][i];
				for (int k=1;k<=n;k++)
					A(a[j][k],-a[i][k]*t);
				if (a[j][i]==0) break;
				swap(a[i],a[j]),f=-f;
			}
    }
    for (int i=1;i<=n;i++) (res*=a[i][i])%=MD;
    return (res*f%MD+MD)%MD;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
    mkid();
    for (int i=1;i<=n;i++)
     for (int j=1;j<=m;j++)
      for (int t=0;t<4;t++)
          if (id[i][j]&&id[i+p[t][0]][j+p[t][1]]) add(id[i][j],id[i+p[t][0]][j+p[t][1]]);
    printf("%lld",det(kir,N-1));
    return 0;
}
