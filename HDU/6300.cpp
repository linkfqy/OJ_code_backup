#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=3005;
int tst,n;
struct point{
    int x,y,id;
    bool operator<(const point&b)const {return x<b.x||x==b.x&&y<b.y;}
}a[maxn];
int main(){
    scanf("%d",&tst);
    while (tst--){
        scanf("%d",&n);
        for (int i=1;i<=3*n;i++) scanf("%d%d",&a[i].x,&a[i].y),a[i].id=i;
        sort(a+1,a+1+3*n);
        for (int i=1;i<=n;i++) printf("%d %d %d\n",a[i*3-2].id,a[i*3-1].id,a[i*3].id);
    }
    return 0;
}
