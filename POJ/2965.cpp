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
�۲���Է��֣�����ĳ��λ��(i,j)������ѵ�i�к͵�j�е����п��ض���һ�Σ�(i,j)ֻ��һ�ξͿ����ˣ� 
��ô�����Ľ��������ͼ����(i,j)�⣬��û�б仯����Ϊ�к��ж���ż��������
���ǵĲ��Ծ��ǣ�����ÿ��'+'������������������ĳһ�㶯��ż�����൱��û�ж�
����ͳ��ĳ�㶯�Ĵ���Ϊ��������ż���������������㼴�� 
*/
