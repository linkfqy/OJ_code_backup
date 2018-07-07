#include<cstdio>
bool a[9][9],b[9][9];
inline char fstchar(){
	char ch=getchar();
	while (ch!='-'&&ch!='+') ch=getchar();
	return ch;
}
void change(int x,int y){
	for (int i=1;i<=4;i++)
	 b[i][y]=!b[i][y],b[x][i]=!b[x][i];
	b[x][y]=!b[x][y];
}
int main(){
	for (int i=1;i<=4;i++){
		a[i][1]=(fstchar()=='+');
		for (int j=2;j<=4;j++) a[i][j]=(getchar()=='+');
	}
	for (int i=1;i<=4;i++)
	 for (int j=1;j<=4;j++)
	  if (a[i][j]) change(i,j);
	int ans=0;
	for (int i=1;i<=4;i++)
	 for (int j=1;j<=4;j++) ans+=b[i][j];
	printf("%d\n",ans);
	for (int i=1;i<=4;i++)
	 for (int j=1;j<=4;j++) if (b[i][j]) printf("%d %d\n",i,j);
	return 0;
}









/*
观察可以发现，对于某个位置(i,j)，如果把第i行和第j列的所有开关都动一次（(i,j)只动一次就可以了） 
那么操作的结果是整张图除了(i,j)外，都没有变化（因为行和列都是偶数个）。
我们的策略就是：对于每个'+'，都进行上述处理，而某一点动了偶数次相当于没有动
可以统计某点动的次数为奇数还是偶数，最后输出奇数点即可 
*/
