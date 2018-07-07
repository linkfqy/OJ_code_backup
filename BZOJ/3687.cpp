#include<cstdio>
#include<bitset>
using namespace std;
int n,ans;
bitset<2000005> S;
int main(){
	scanf("%d",&n);
	S.set(0);
	for (int i=1,x;i<=n;i++)
	 scanf("%d",&x),S=(S<<x)^S;
	for (int i=1;i<=2000000;i++)
	 if (S.test(i)) ans^=i;
	return printf("%d",ans),0;
}
