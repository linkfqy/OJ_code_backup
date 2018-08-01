#include<cstdio>
#include<cstring>
#define cl(x,y) memset(x,y,sizeof(x))

const int maxn=105;
const char s[5][6]={"  +-+"," /./|","+-+.+","|.|/ ","+-+  "};
int tst,a,b,c,n,m;
char map[maxn][maxn];
void draw(int x,int y){ //printf("draw %d %d\n",x,y);
    for (int i=0;i<5;i++)
        for (int j=0;j<5;j++)
            if (s[i][j]!=' ') map[x+i][y+j]=s[i][j];
}
int main(){
    scanf("%d",&tst);
    while (tst--){
        scanf("%d%d%d",&a,&b,&c);//printf("%d %d %d\n",a,b,c);
        cl(map,'.');
        n=(b+c)*2+1;m=(a+b)*2+1;//printf("%d %d\n",n,m);
        for (int k=1;k<=c;k++)
            for (int j=b;j>=1;j--)
                for (int i=1;i<=a;i++)
                    draw(2*(b-j)+2*(c-k)+1,2*(i-1)+2*(j-1)+1);
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++)
                putchar(map[i][j]);
            putchar('\n');
        }
    }
    return 0;
}
