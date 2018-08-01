#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=105;
int tst,n,m,p[maxn+5];
int main(){
    scanf("%d",&tst);
    while (tst--){
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) scanf("%d%d",&p[i],&p[i]),p[i]++;
        sort(p+1,p+1+n);
        ll s=1;int ans=0;
        for (int i=1;i<=n;i++){
            s*=p[i];if (s>m) break;
            ans=i;
        }
        printf("%d\n",ans);
    }
    return 0;
}
