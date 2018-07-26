#include<cstdio>
#include<cstring>
#define cl(x,y) memset(x,y,sizeof(x))
typedef unsigned long long ull;
using namespace std;

const int maxn=2005;
const int maxs=2005,MOD=10007;
int tst,n,q,f[maxn][maxn]; ull pw[maxn],h[maxn];
char s[maxn];
inline ull gethash(int l,int r){
    return h[r]-h[l-1]*pw[r-l+1];
}
struct hashmap{
	int lnk[MOD+5],nxt[maxs],son[maxs],tot;ull w[maxs];
	inline void clear() {cl(lnk,0);tot=0;}
	inline void add(ull x,int y){
		son[++tot]=y;nxt[tot]=lnk[x%MOD];lnk[x%MOD]=tot;w[tot]=x;
	}
	inline int* ask(ull x){
		for (int j=lnk[x%MOD];j;j=nxt[j])
		 if (w[j]==x) return &son[j];
		return NULL; 
	}
}lst;
int main(){
    pw[0]=1;for (int i=1;i<=2000;i++) pw[i]=pw[i-1]*233;
    scanf("%d",&tst);
    while (tst--){
        scanf("%s%d",s+1,&q);n=strlen(s+1);
        for (int i=1;i<=n;i++) h[i]=h[i-1]*233+s[i];
        cl(f,0);
        for (int L=1;L<=n;L++){
        	lst.clear();
        	for (int i=1;i+L-1<=n;i++){int j=i+L-1;
        		f[i][j]++;ull hhh=gethash(i,j);
        		if (lst.ask(hhh)!=NULL) f[*lst.ask(hhh)][j]--,*lst.ask(hhh)=i;else lst.add(hhh,i);
			}
		}
        for (int i=n;i>=1;i--)
         for (int j=i;j<=n;j++) f[i][j]+=f[i+1][j]+f[i][j-1]-f[i+1][j-1];
        while (q--){
            int l,r;scanf("%d%d",&l,&r);
            printf("%d\n",f[l][r]);
        }
    } 
    return 0;
}
