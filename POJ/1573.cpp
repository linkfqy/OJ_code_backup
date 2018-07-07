#include<cstdio>
#include<cstring>
const int maxn=15,p[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int a[maxn][maxn],num[128],hsh[maxn][maxn];
int n,m,k;
struct ha{
	int x,y;
}que[maxn*maxn];
inline char fstchar(){
	char ch=getchar();
	while (ch<'A'||'Z'<ch) ch=getchar();
	return ch;
}
void doit(){
	memset(hsh,0,sizeof(hsh));
	int til=1,x=1,y=k;
	que[1]=(ha){1,k};hsh[1][k]=1;
	while (1<=x&&x<=n&&1<=y&&y<=m){
		int t=a[x][y];
		que[++til]=(ha){x+p[t][0],y+p[t][1]};
		if (hsh[x+p[t][0]][y+p[t][1]]) break;
		x+=p[t][0];y+=p[t][1];
		hsh[x][y]=til;
	}
	if (1<=x&&x<=n&&1<=y&&y<=m){
		printf("%d step(s) before a loop of %d step(s)\n",hsh[que[til].x][que[til].y]-1,til-hsh[que[til].x][que[til].y]);
		return;
	}else printf("%d step(s) to exit\n",til-1);
}
int main(){
	num['N']=0;num['E']=1;num['S']=2;num['W']=3;
	scanf("%d%d%d",&n,&m,&k);
	while (n){
		for (int i=1;i<=n;i++){
			a[i][1]=num[fstchar()];
			for (int j=2;j<=m;j++)
			 a[i][j]=num[getchar()];
		}
		doit();
		scanf("%d%d%d",&n,&m,&k);
	}
	return 0;
}
