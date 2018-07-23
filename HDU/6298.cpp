#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

int tst,n;
int main(){
    scanf("%d",&tst);
    while (tst--){
        scanf("%d",&n);
        if (n%3==0) printf("%lld\n",(ll)(n/3)*(n/3)*(n/3));else{
            int x=n/2,y=x/2;
            if (x+2*y==n) printf("%lld\n",(ll)x*y*y);else puts("-1");
        }
    }
    return 0;
}
