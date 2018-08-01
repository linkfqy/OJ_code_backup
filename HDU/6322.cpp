#include<cstdio>
using namespace std;

int te,n;

int main(){
    for (scanf("%d",&te);te;te--){
        scanf("%d",&n);
        if (n==1) puts("5");
        else printf("%d\n",n+5);
    }
    return 0;
}
