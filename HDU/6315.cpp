#include<cstdio>
#include<cctype>
#include<algorithm>
#define fr first
#define sc second
#define mp make_pair
using namespace std;
typedef pair<int,int> data;
const int maxn=100000;

int n,te,b[maxn+5],c[maxn+5];
int ID[(maxn<<2)+5],MIN[(maxn<<2)+5],tag[(maxn<<2)+5];

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
inline void Update(int x,int tem) {for (int i=x;i<=n;i+=i&-i) c[i]+=tem;}
inline int Sum(int x) {int sum=0;for (int i=x;i;i-=i&-i) sum+=c[i];return sum;}
inline void Pushup(int p){
    if (MIN[p<<1]<MIN[p<<1|1]) MIN[p]=MIN[p<<1],ID[p]=ID[p<<1];
    else MIN[p]=MIN[p<<1|1],ID[p]=ID[p<<1|1];
}
void Build(int L,int R,int p=1){
    tag[p]=0;if (L==R) {ID[p]=L;MIN[p]=b[L];return;}int mid=L+(R-L>>1);
    Build(L,mid,p<<1);Build(mid+1,R,p<<1|1);Pushup(p);
}
inline void Pushdown(int p){
    int now=tag[p];tag[p]=0;if (!now) return;
    MIN[p<<1]+=now;tag[p<<1]+=now;MIN[p<<1|1]+=now;tag[p<<1|1]+=now;
}
void Insert(int L,int R,int k,int l=1,int r=n,int p=1){
    if (R<l||r<L) return;if (L<=l&&r<=R) {MIN[p]+=k;tag[p]+=k;return;}int mid=l+(r-l>>1);
    Pushdown(p);Insert(L,R,k,l,mid,p<<1);Insert(L,R,k,mid+1,r,p<<1|1);Pushup(p);
}
data Min(int L,int R,int l=1,int r=n,int p=1){
    if (R<l||r<L) return mp(2e9,0);if (L<=l&&r<=R) return mp(MIN[p],ID[p]);int mid=l+(r-l>>1);
    Pushdown(p);return min(Min(L,R,l,mid,p<<1),Min(L,R,mid+1,r,p<<1|1));
}
inline void Add(int L,int R){
    Insert(L,R,-1);data now=Min(L,R);
    while (!now.fr){
        Insert(now.sc,now.sc,b[now.sc]);
        Update(now.sc,1);now=Min(L,R);
    }
}
inline int Ask(int L,int R) {return Sum(R)-Sum(L-1);}
int main(){
    while (~readi(n)){
        readi(te);for (int i=1;i<=n;i++) readi(b[i]),c[i]=0;
        for (Build(1,n);te;te--){
            char ch=readc();while (!islower(ch)) ch=readc();
            int L,R;readi(L);readi(R);
            if (ch=='a') Add(L,R); else printf("%d\n",Ask(L,R));
        }
    }
    return 0;
}
