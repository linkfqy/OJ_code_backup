#include<cstdio>
#include<algorithm>
using namespace std;
const int m[4][4]={4,8,12,16},p[5][2]={{0,1},{1,0},{0,-1},{-1,0},{0,0}};
bool a[9][9],b[9][9];
int ans=20;
inline char fstchar(){
	char ch=getchar();
	while (ch!='w'&&ch!='b') ch=getchar();
	return ch;
}
bool check(int x,int y){
	return (0<=x&&x<4&&0<=y&&y<4);
}
int main(){
	for (int i=0;i<4;i++){
		b[i][0]=(fstchar()=='w');
		for (int j=1;j<4;j++) b[i][j]=(getchar()=='w');
	}
	for (int s=0;s<65536;s++){
		for (int i=0;i<4;i++)
		 for (int j=0;j<4;j++) a[i][j]=b[i][j];
		int sum=0;
		for (int j=0;j<16;j++)
		 if (s&(1<<j)){ sum++;
		 	int x=j/4,y=j%4;
		 	for (int i=0;i<5;i++)
		 	 if (check(x+p[i][0],y+p[i][1])) a[x+p[i][0]][y+p[i][1]]=!a[x+p[i][0]][y+p[i][1]];
		 }
		bool suc=1;
		for (int i=0;i<4;i++)
		 for (int j=0;j<4;j++)
		  if (a[i][j]) suc=0;
		if (suc) ans=min(ans,sum);
	}
	for (int s=0;s<65536;s++){
		for (int i=0;i<4;i++)
		 for (int j=0;j<4;j++) a[i][j]=!b[i][j];
		int sum=0;
		for (int j=0;j<16;j++)
		 if (s&(1<<j)){ sum++;
		 	int x=j/4,y=j%4;
		 	for (int i=0;i<5;i++)
		 	 if (check(x+p[i][0],y+p[i][1])) a[x+p[i][0]][y+p[i][1]]=!a[x+p[i][0]][y+p[i][1]];
		 }
		bool suc=1;
		for (int i=0;i<4;i++)
		 for (int j=0;j<4;j++)
		  if (a[i][j]) suc=0;
		if (suc) ans=min(ans,sum);
	}
	if (ans==20) printf("Impossible");else printf("%d",ans);
	return 0;
}
