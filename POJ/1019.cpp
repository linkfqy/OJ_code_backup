#include<cstdio>
#define LL long long
int tst,stk[10];
inline int getlen(int x){
	int res=0;
	do res++,x/=10; while (x);
	return res;
}
int getdig(LL x){
	for (int i=1;;i++){
		int j=i;stk[0]=0;
		do stk[++stk[0]]=j%10,j/=10; while (j);
		while (stk[0]){
			x--;stk[0]--;
			if (!x) return stk[stk[0]+1];
		}
	}
}
int main(){
	scanf("%d",&tst);
	while (tst--){
		LL x,sum,now;int lst;
		scanf("%lld",&x);
		lst=1;now=1;sum=0;
		while (sum+now<x)
		 sum+=now,
		 now+=getlen(++lst);
		printf("%d\n",getdig(x-sum));
	}
	return 0;
}


























/*
���԰����п����ɶ�������й��ɣ� 
S1,S2,S3����Sk
Si��ʾ��'1'Ϊ��㣬iΪ��β��һ��
��ôֻ�����x���Ǹ��������У�ʣ�µ�һ��һ���Ƽ��� 
*/
