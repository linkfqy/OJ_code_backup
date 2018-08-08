#include<cstdio>
#include<cmath>
using namespace std;
typedef long double DB;
const DB g=9.8;

int te,A,B,X,Y;DB AL,K,L,vx,vy,a,T;

inline int fcmp(DB a,DB b) {if (fabs(a-b)<1e-8) return 0;return a<b?-1:1;}
int main(){
    for (scanf("%d",&te);te;te--){
        scanf("%d%d%d%d",&A,&B,&X,&Y);X=-X;K=(DB)B/A;AL=atan(K);
        vx=sqrt(2*(Y-K*X)*g);vy=vx*sin(AL);vx*=cos(AL);T=2*vx/g/cos(AL);
        L=sqrt((K*X)*(K*X)+X*X);a=g*sin(AL);int ans=0;
        while (fcmp(L,0)>0) ans++,L-=(vy+vy+T*a)*T/2,vy+=T*a;
        printf("%d\n",ans);
    }
    return 0;
}
