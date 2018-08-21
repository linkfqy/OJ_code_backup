#include<cstdio>

const int maxn=100005;
int n,x,a[maxn],num[2][maxn];
int main(){
	scanf("%d%d",&n,&x);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),num[0][a[i]]++,num[1][a[i]&x]++;
	for (int i=0;i<=100000;i++)
	 if (num[0][i]>1) return puts("0"),0;
	for (int i=1;i<=n;i++){
		num[0][a[i]]--;
		if (num[0][a[i]&x]) return puts("1"),0;
		num[0][a[i]]++;
	}
	for (int i=0;i<=100000;i++)
	 if (num[1][i]>1) return puts("2"),0;
	return puts("-1"),0;
}
