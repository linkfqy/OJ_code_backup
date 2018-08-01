#include<cstdio>
#include<cmath>
#include<algorithm>
#define _abs(x) ((x)>0?(x):-(x))
using namespace std;

const int maxn=100005;
int tst,n,a[maxn];
int main(){
    for (scanf("%d",&tst);tst;tst--){
        scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        printf("%d\n",(int)sqrt(_abs(a[1]-a[n])));
    }
    return 0;
}
