#include<cstdio>
int n,now,num;
int main(){
	scanf("%d",&n);
	for (int i=1,x;i<=n;i++){
		scanf("%d",&x);
		if (num==0) now=x;
		if (x==now) num++;else num--;
	}
	printf("%d",now);
	return 0;
}
