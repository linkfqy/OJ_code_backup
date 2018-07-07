#include<cstdio>
#include<cstring>
const int maxm=35,maxt=1005;
int m,t,n;
double p[maxt][maxm],g[maxt][maxm][maxm];
int main(){
	for (scanf("%d%d%d",&m,&t,&n);m;scanf("%d%d%d",&m,&t,&n)){
		memset(g,0,sizeof(g));
		for (int i=1;i<=t;i++)
		 for (int j=1;j<=m;j++) scanf("%lf",&p[i][j]);
		double p1=1,p2=1;
		for (int i=1;i<=t;i++){
			double sum=1;
			for (int j=1;j<=m;j++)
			 sum*=1-p[i][j];
			p1*=1-sum;
		}
		for (int i=1;i<=t;i++){
			g[i][0][0]=1;
			for (int j=1;j<=m;j++){
				g[i][j][0]=g[i][j-1][0]*(1-p[i][j]);
				for (int k=1;k<=j;k++)
				 g[i][j][k]=g[i][j-1][k-1]*p[i][j]+g[i][j-1][k]*(1-p[i][j]);
			}
			double sum=0;
			for (int k=1;k<n;k++) sum+=g[i][m][k];
			p2*=sum;
		}
		printf("%.3f\n",p1-p2);
	}
	return 0;
}



























/*
典型的概率DP。 
设p1为【所有队伍都至少A了一道题】的概率
设p2为【所有队伍都A了1~n-1道题】的概率 
则p1=1-【有一个队伍A了0题】的概率=p2+(1-p2)-【有一个队伍A了0题】的概率=p2+【不是所有队伍都A了1~n-1题】的概率-【有一个队伍A了0题】的概率
那么答案就是p1-p2
p1很好求，就是【队伍i至少A了一道题】的概率之积，对于队伍i，它至少A了一道题就是1-【A了0道题】的概率
p2可以用DP求得：
g[i][j][k]表示队伍i在前j道题中，A了k道题的概率
g[i][j][k]=g[i][j-1][k-1]*p[i][j]+g[i][j-1][k]*(1-p[i][j])
p2就是【队伍iA了1~n-1道题】的概率之积，即g[i][m][1~n-1]之积 
*/
