#include <cstdio>
#include <cctype>
using namespace std;

int ti,hh,mm,wz,k;
char s[10];
int X,Y;

int main(){
    for (scanf("%d",&ti); ti; --ti){
        X=0,Y=0;
        scanf("%d%d%s",&hh,&mm,s+1);
        X=s[5]-'0',wz=5;
        if (isdigit(s[6])) X=X*10+s[6]-'0',wz=6;
        if (s[wz+1]=='.') Y=s[wz+2]-'0';
        if (s[4]=='-') X=-X,Y=-Y;
        hh=hh+X-8;mm+=6*Y;
        if (mm>=60) mm-=60,hh++;
        if (mm<0) mm+=60,hh--;
        hh=(hh%24+24)%24;
        printf("%02d:%02d\n",hh,mm);
    }
    return 0;
}
