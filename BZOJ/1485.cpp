#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=2000005;
int n,MOD,p[maxn],nxt[maxn],num[maxn];
bool vis[maxn];
void makep(int n){
	for (int i=2;i<=n;i++){
		if (!vis[i]) p[++p[0]]=i,nxt[i]=i;
		for (int j=1;j<=p[0]&&i*p[j]<=n;j++){
			vis[i*p[j]]=1;nxt[i*p[j]]=p[j];
			if (i%p[j]==0) break;
		}
	}
}
inline void add(int x,int f){
	for (;x>1;x/=nxt[x]) num[nxt[x]]+=f;
}
int main(){
	scanf("%d%d",&n,&MOD);
	makep(2*n);
	for (int i=n+2;i<=2*n;i++) add(i,1);
	for (int i=1;i<=n;i++) add(i,-1);
	long long ans=1;
	for (int i=1;i<=p[0];i++)
	 for (int j=1;j<=num[p[i]];j++)
	  (ans*=p[i])%=MOD;
	printf("%lld",ans);
	return 0;
}
