#include<cstdio>

int main(){
	int n;scanf("%d",&n);
	for (int i=1;i<=n;i++) putchar('0'+(i&1));
	return 0;
}
