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
一看就知道是要求前缀和了……
这次我们的前缀和RN(i)表示[1,i)内的round number数
求前缀和的过程：
设现求RN(x)，二进制下x长度为A0 
首先求二进制下长度小于A0的round number个数，
若长度为i，则有i-1位可自由支配（不能有前导0）设放j个0，则方案数为c(i-1,j)，显然j∈[(i+1)/2,i)
再看长度==A0的round number个数，
为了保证记录的方案数是小于x的round number，对于x的第i位若是0就没有新的方案，若是1则可以变为0（前面的1还是1），
那么后面i-1位就是可自由支配的了，设放j个0，则方案数为c(i-1,j)，显然j∈[(i+1)/2-num0-1,i)其中num0为前面处理过的0的个数
那么RN(x)就求完了，对于组合数的求解，直接套杨辉三角 
*/
