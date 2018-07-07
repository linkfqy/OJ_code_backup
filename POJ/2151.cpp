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
���͵ĸ���DP�� 
��p1Ϊ�����ж��鶼����A��һ���⡿�ĸ���
��p2Ϊ�����ж��鶼A��1~n-1���⡿�ĸ��� 
��p1=1-����һ������A��0�⡿�ĸ���=p2+(1-p2)-����һ������A��0�⡿�ĸ���=p2+���������ж��鶼A��1~n-1�⡿�ĸ���-����һ������A��0�⡿�ĸ���
��ô�𰸾���p1-p2
p1�ܺ��󣬾��ǡ�����i����A��һ���⡿�ĸ���֮�������ڶ���i��������A��һ�������1-��A��0���⡿�ĸ���
p2������DP��ã�
g[i][j][k]��ʾ����i��ǰj�����У�A��k����ĸ���
g[i][j][k]=g[i][j-1][k-1]*p[i][j]+g[i][j-1][k]*(1-p[i][j])
p2���ǡ�����iA��1~n-1���⡿�ĸ���֮������g[i][m][1~n-1]֮�� 
*/
