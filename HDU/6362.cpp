#include <cstdio>
#include <cmath>
using namespace std;

const double pi=acos(-1.0);
int ti,a,b;

int main(void){
    for (scanf("%d",&ti); ti; --ti){
        scanf("%d%d",&a,&b);
        double t=a*pi+2*b;
        long long ans=t*1000000;
        printf("%.6f\n",ans*1.0/1000000);
    }
    return 0;
}
