#include<cstdio>

const int maxn=100005;
int n,K,a[maxn];
inline int gcd(int x,int y) {return y==0?x:gcd(y,x%y);}
int main(){
	scanf("%d%d",&n,&K);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int g=K;
	for (int i=1;i<=n;i++) g=gcd(g,a[i]);
	printf("%d\n",K/g);
	for (int i=0;i<K;i+=g) printf("%d ",i);
	return 0;
}
