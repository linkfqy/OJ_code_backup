#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=105,maxs=10005;
int c,n[3],f[maxs],fa[maxs],ans,wht[maxs],who[maxs];
bool vis[maxn][maxn];
struct ha{
	int a[3];
	void c(int x,int y){a[1]=x;a[2]=y;}
}que[maxs];
bool bfs(){
	int hed=0,til=1;
	que[1].c(0,0);vis[0][0]=1;f[1]=0;
	while (hed!=til){
		hed++;
		for (int i=1;i<=2;i++){
			ha x=que[hed];x.a[i]=0;
			if (!vis[x.a[1]][x.a[2]]){
				vis[x.a[1]][x.a[2]]=1;
				que[++til]=x;f[til]=f[hed]+1;fa[til]=hed;wht[til]=1;who[til]=i;
			}
			x=que[hed];x.a[i]=n[i];
			if (!vis[x.a[1]][x.a[2]]){
				vis[x.a[1]][x.a[2]]=1;
				que[++til]=x;f[til]=f[hed]+1;fa[til]=hed;wht[til]=2;who[til]=i;
				if (n[i]==c) {ans=til;return 1;}
			}
			x=que[hed];
			int M=min(n[i]-x.a[i],x.a[3-i]);
			x.a[i]+=M;x.a[3-i]-=M;
			if (!vis[x.a[1]][x.a[2]]){
				vis[x.a[1]][x.a[2]]=1;
				que[++til]=x;f[til]=f[hed]+1;fa[til]=hed;wht[til]=3;who[til]=i;
				if (x.a[1]==c||x.a[2]==c) {ans=til;return 1;}
			}
		}
	}
	return 0;
}
int stk[maxs];
int main(){
	scanf("%d%d%d",&n[1],&n[2],&c);
	if (!bfs()) printf("impossible");else{
		printf("%d\n",f[ans]);
		for (;ans;ans=fa[ans]) stk[++stk[0]]=ans;
		for (int i=stk[0]-1;i;i--)
		 if (wht[stk[i]]==2) printf("FILL(%d)\n",who[stk[i]]);else
		 if (wht[stk[i]]==1) printf("DROP(%d)\n",who[stk[i]]);else
		 printf("POUR(%d,%d)\n",3-who[stk[i]],who[stk[i]]);
	}
	return 0;
}
