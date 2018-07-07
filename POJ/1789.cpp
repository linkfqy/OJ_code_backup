#include<cstdio>
#include<cstring>
const int maxn=2005;
int n,ans,cst[maxn][maxn],dst[maxn];
char s[maxn][10];
bool vis[maxn];
inline char fstchar(){
	char ch=getchar();
	while (ch<'a'||'z'<ch) ch=getchar();
	return ch;
}
int getdst(int i,int j){
	int res=0;
	for (int k=1;k<=7;k++) res+=s[i][k]!=s[j][k];
	return res;
}
void prim(){
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++) dst[i]=cst[1][i];vis[1]=1;
	for (int i=1;i<n;i++){
		int Min=0x3f3f3f3f,k;
		for (int j=2;j<=n;j++)
		 if (!vis[j]&&Min>dst[j]) Min=dst[j],k=j;
		ans+=Min;vis[k]=1;
		for (int j=2;j<=n;j++)
		 if (dst[j]>cst[k][j]) dst[j]=cst[k][j];
	}
}
int main(){
	scanf("%d",&n);
	while (n){
		for (int i=1;i<=n;i++){
			s[i][1]=fstchar();cst[i][i]=0;
			for (int j=2;j<=7;j++) s[i][j]=getchar();
			for (int j=1;j<i;j++)
			 cst[i][j]=cst[j][i]=getdst(i,j);
		}
		ans=0;
		prim();
		printf("The highest possible quality is 1/%d.\n",ans);
		scanf("%d",&n);
	}
	return 0;
}
