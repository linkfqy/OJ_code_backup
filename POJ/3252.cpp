#include<cstdio>
int a[35],c[35][35];
void make_c(){
	for (int i=0;i<=31;i++){
		c[i][0]=1;
		for (int j=1;j<=i;j++) c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
}
int RN(int x){
	a[0]=0;
	do a[++a[0]]=x&1,x>>=1; while (x);
	int res=0,num0=0;
	for (int i=1;i<a[0];i++)
	 for (int j=i+1>>1;j<i;j++) res+=c[i-1][j];
	for (int i=a[0]-1;i;i--)
	 if (a[i]) for (int j=(a[0]+1>>1)-num0-1;j<i;j++) res+=c[i-1][j];else num0++;
	return res;
}
int main(){
	make_c();
	int l,r;scanf("%d%d",&l,&r);
	printf("%d",RN(r+1)-RN(l));
	return 0;
}



























/*
һ����֪����Ҫ��ǰ׺���ˡ���
������ǵ�ǰ׺��RN(i)��ʾ[1,i)�ڵ�round number��
��ǰ׺�͵Ĺ��̣�
������RN(x)����������x����ΪA0 
������������³���С��A0��round number������
������Ϊi������i-1λ������֧�䣨������ǰ��0�����j��0���򷽰���Ϊc(i-1,j)����Ȼj��[(i+1)/2,i)
�ٿ�����==A0��round number������
Ϊ�˱�֤��¼�ķ�������С��x��round number������x�ĵ�iλ����0��û���µķ���������1����Ա�Ϊ0��ǰ���1����1����
��ô����i-1λ���ǿ�����֧����ˣ����j��0���򷽰���Ϊc(i-1,j)����Ȼj��[(i+1)/2-num0-1,i)����num0Ϊǰ�洦�����0�ĸ���
��ôRN(x)�������ˣ��������������⣬ֱ����������� 
*/
