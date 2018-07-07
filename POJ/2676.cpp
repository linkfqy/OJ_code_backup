#include<cstdio>
#include<cstring>
const int maxn=11,p[10][10]={{0,0,0,0,0,0,0,0,0,0},
							 {0,1,1,1,2,2,2,3,3,3},
							 {0,1,1,1,2,2,2,3,3,3},
							 {0,1,1,1,2,2,2,3,3,3},
							 {0,4,4,4,5,5,5,6,6,6},
							 {0,4,4,4,5,5,5,6,6,6},
							 {0,4,4,4,5,5,5,6,6,6},
							 {0,7,7,7,8,8,8,9,9,9},
							 {0,7,7,7,8,8,8,9,9,9},
							 {0,7,7,7,8,8,8,9,9,9}};
int tst;
char a[maxn][maxn];
bool h[maxn][maxn],l[maxn][maxn],s[maxn][maxn],suc;
inline char fstchar(){
	char ch=getchar();
	while (ch<'0'||'9'<ch) ch=getchar();
	return ch;
}
void dfs(int x,int y){
	if (suc) return;
	if (x>9){suc=1;return;}
	int xx=x,yy=y+1;
	if (yy>9) xx++,yy=1;
	if (a[x][y]) {dfs(xx,yy);return;}
	for (int i=1;i<=9;i++)
	 if (!h[x][i]&&!l[y][i]&&!s[p[x][y]][i]){
	 	h[x][i]=l[y][i]=s[p[x][y]][i]=1;
	 	a[x][y]=i;dfs(xx,yy);if (suc) return;
		a[x][y]=0;
	 	h[x][i]=l[y][i]=s[p[x][y]][i]=0;
	 }
}
int main(){
	scanf("%d",&tst);
	while (tst--){
		memset(h,0,sizeof(h));
		memset(l,0,sizeof(l));
		memset(s,0,sizeof(s));
		for (int i=1;i<=9;i++){
			a[i][1]=fstchar()-48;
			for (int j=2;j<=9;j++) a[i][j]=getchar()-48;
		}
		for (int i=1;i<=9;i++)
		 for (int j=1;j<=9;j++)
		  if (a[i][j]) h[i][a[i][j]]=l[j][a[i][j]]=s[p[i][j]][a[i][j]]=1;
		suc=0;dfs(1,1);
		for (int i=1;i<=9;i++){
			for (int j=1;j<=9;j++) putchar(a[i][j]+48);
			putchar(10);
		}
	}
	return 0;
}
