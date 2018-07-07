#include<cstdio>
 
const int maxn=100005;
int n,m,a[maxn],ans=0,now=0;
char op[maxn];
inline int red(){
    int res=0;char ch=getchar();
    while (ch<'0'||'9'<ch) ch=getchar();
    while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=getchar();
    return res;
}
inline char fstchar(){
    char ch=getchar();
    while (ch<'A'||'Z'<ch) ch=getchar();
    return ch;
}
inline bool w(int l,int x){
    int res=x<<l;
    for (int i=1;i<=n;i++)
     if (op[i]=='O') res|=a[i];else
     if (op[i]=='A') res&=a[i];else
     res^=a[i];
    return (res>>l)&1;
}
int main(){
    n=red(),m=red();
    for (int i=1;i<=n;i++) op[i]=fstchar(),a[i]=red();
    for (int i=30;i>=0;i--)
     if (w(i,0)) ans+=(1<<i);else
     if (w(i,1)&&now+(1<<i)<=m) now+=(1<<i),ans+=(1<<i);
    printf("%d",ans);
    return 0;
}
