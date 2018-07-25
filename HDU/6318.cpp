#include<cstdio>
#include<cctype>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=100000;

int n,X,Y,a[maxn+5],b[maxn+5],c[maxn+5];LL ans;

#define Eoln(x) ((x)==10||(x)==13||(x)==EOF)
inline char readc(){
    static char buf[100000],*l=buf,*r=buf;
    if (l==r) r=(l=buf)+fread(buf,1,100000,stdin);
    if (l==r) return EOF;return *l++;
}
inline int readi(int &x){
    int tot=0;char ch=readc(),lst='+';
    while (!isdigit(ch)) {if (ch==EOF) return EOF;lst=ch;ch=readc();}
    while (isdigit(ch)) tot=(tot<<3)+(tot<<1)+(ch^48),ch=readc();
    return (lst=='-'?x=-tot:x=tot),Eoln(ch);
}
inline int Find(int x){
    int L=1,R=b[0],mid;
    while (L<=R) {mid=L+(R-L>>1);if (b[mid]==x) return mid;x<b[mid]?R=mid-1:L=mid+1;}
}
inline void Update(int x,int tem) {for (int i=x;i<=b[0];i+=i&-i) c[i]+=tem;}
inline int Sum(int x) {int sum=0;for (int i=x;i;i-=i&-i) sum+=c[i];return sum;}
int main(){
    while (~readi(n)){
        readi(X);readi(Y);for (int i=1;i<=n;i++) readi(a[i]),b[i]=a[i];
        sort(b+1,b+1+n);b[0]=unique(b+1,b+1+n)-b-1;ans=0;
        for (int i=1;i<=n;i++) a[i]=Find(a[i]),c[i]=0;
        for (int i=n;i;i--) ans+=Sum(a[i]-1),Update(a[i],1);
        if (X<Y) ans*=X; else ans*=Y;printf("%lld\n",ans);
    }
    return 0;
}
