#include<cstdio>
#include<cctype>
#include<algorithm>
#define fr first
#define sc second
using namespace std;
const int maxn=100000;

int te,n,m,ans[maxn+5];pair<int,int> a[maxn+5];
int sum[(maxn<<2)+5];

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
void Build(int L,int R,int p=1){
    if (L==R) {sum[p]=1;return;}int mid=L+(R-L>>1);
    Build(L,mid,p<<1);Build(mid+1,R,p<<1|1);sum[p]=sum[p<<1]+sum[p<<1|1];
}
void Insert(int pos,int k,int l=1,int r=n,int p=1){
    if (l==r) {sum[p]+=k;return;}int mid=l+(r-l>>1);
    if (pos<=mid) Insert(pos,k,l,mid,p<<1); else Insert(pos,k,mid+1,r,p<<1|1);
    sum[p]=sum[p<<1]+sum[p<<1|1];
}
int Find(int L=1,int R=n,int p=1){
    if (L==R) return L;int mid=L+(R-L>>1);
    if (sum[p<<1]) return Find(L,mid,p<<1); else return Find(mid+1,R,p<<1|1);
}
inline bool cmp(const pair<int,int> &a,const pair<int,int> &b) {return a.fr<b.fr||a.fr==b.fr&&a.sc>b.sc;}
int main(){
    for (readi(te);te;te--){
        readi(n);readi(m);for (int i=1;i<=m;i++) readi(a[i].fr),readi(a[i].sc);
        sort(a+1,a+1+m,cmp);int MAX=a[1].sc,tot=1;Build(1,n);
        for (int i=2;i<=m;i++) if (a[i].sc>MAX) a[++tot]=a[i],MAX=a[i].sc;m=tot;
        for (int i=1;i<a[1].fr;i++) ans[i]=1;
        for (int i=a[1].fr;i<=a[1].sc;i++) ans[i]=i-a[1].fr+1,Insert(ans[i],-1);
        int L=a[1].fr,R=a[1].sc;
        for (int i=2;i<=m;i++){
            if (a[i-1].sc<a[i].fr) {while (L<=R) Insert(ans[L++],1);while (L<a[i].fr) ans[L++]=1;R=L-1;}
            while (L<a[i].fr) Insert(ans[L++],1);
            while (R<a[i].sc) {int now=Find();ans[++R]=now;Insert(ans[R],-1);}
        }
        for (int i=a[m].sc+1;i<=n;i++) ans[i]=1;
        for (int i=1;i<=n;i++) i>1?printf(" %d",ans[i]):printf("%d",ans[i]);puts("");
    }
    return 0;
}
