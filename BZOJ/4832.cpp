#include<cstdio>
#include<cstring>
#define cl(x,y) memset(x,y,sizeof(x))

int tst,K,A,B,C;
double f[55][10][10][10],g[55][10][10][10];
bool vis[55][10][10][10];
int main(){
	scanf("%d",&tst);
	while (tst--){
		scanf("%d%d%d%d",&K,&A,&B,&C);
		cl(f,0);cl(g,0);cl(vis,0);
		vis[K][A][B][C]=1;g[K][A][B][C]=1;
		for (int i=K;i>=1;i--)
			for (int a=0;a<=7;a++)
				for (int b=0;b<=7;b++)
					for (int c=0;c<=7;c++){
						if (!vis[i][a][b][c]||a+b+c>7) continue;
						g[i-1][a][b][c]+=g[i][a][b][c]/(a+b+c+1);
						f[i-1][a][b][c]+=(f[i][a][b][c]+g[i][a][b][c])/(a+b+c+1);
						vis[i-1][a][b][c]=1;
						if (c)
							if (a+b+c<7){
								g[i-1][a][b+1][c]+=g[i][a][b][c]*c/(a+b+c+1);
								f[i-1][a][b+1][c]+=f[i][a][b][c]*c/(a+b+c+1);
								vis[i-1][a][b+1][c]=1;
							}
							else{
								g[i-1][a][b+1][c-1]+=g[i][a][b][c]*c/(a+b+c+1);
								f[i-1][a][b+1][c-1]+=f[i][a][b][c]*c/(a+b+c+1);
								vis[i-1][a][b+1][c-1]=1;
							}
						if (b)
							if (a+b+c<7){
								g[i-1][a+1][b-1][c+1]+=g[i][a][b][c]*b/(a+b+c+1);
								f[i-1][a+1][b-1][c+1]+=f[i][a][b][c]*b/(a+b+c+1);
								vis[i-1][a+1][b-1][c+1]=1;
							}
							else{
								g[i-1][a+1][b-1][c]+=g[i][a][b][c]*b/(a+b+c+1);
								f[i-1][a+1][b-1][c]+=f[i][a][b][c]*b/(a+b+c+1);
								vis[i-1][a+1][b-1][c]=1;
							}
						if (a){
							g[i-1][a-1][b][c]+=g[i][a][b][c]*a/(a+b+c+1);
							f[i-1][a-1][b][c]+=f[i][a][b][c]*a/(a+b+c+1);
							vis[i-1][a-1][b][c]=1;
						}
					}
		double ans=0;
		for (int a=0;a<=7;a++)
			for (int b=0;b<=7;b++)
				for (int c=0;c<=7;c++)
					if (vis[0][a][b][c]&&a+b+c<=7) ans+=f[0][a][b][c];
		printf("%.2lf\n",ans);
	}
	return 0;
}
