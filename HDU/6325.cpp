#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
inline char nc(){
    static char buf[100000],*l=buf,*r=buf;
    return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++;
}
inline int red(){
    int res=0,f=1;char ch=nc();
    while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
    while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
    return res*f;
}

const int maxn=200005;
int tst,n,stk[maxn],len,id[maxn];
struct point{
    ll x,y;int id;
    point () {}
    point (ll _x,ll _y) :x(_x),y(_y) {}
    bool operator<(const point&b)const {return x<b.x||x==b.x&&y<b.y;}
}a[maxn];
typedef point vec;
inline vec operator-(const point&a,const point&b) {return vec(a.x-b.x,a.y-b.y);}
inline ll cross(const vec&a,const vec&b) {return a.x*b.y-a.y*b.x;}
int main(){
    tst=red();
    while (tst--){
        n=red();
        for (int i=1;i<=n;i++) a[i].x=red(),a[i].y=red(),a[i].id=i;
        sort(a+1,a+1+n);
        len=0;
        for (int i=1;i<=n;i++){
            while (len>1){
                ll c=cross(a[stk[len]]-a[stk[len-1]],a[i]-a[stk[len-1]]);
                if (c>0||c==0&&a[stk[len]].id>a[i].id) len--;else break;
            }
            if (len==0||a[i].x!=a[stk[len]].x) stk[++len]=i;
        }
        for (int i=1;i<=len;i++)
            if (i<len) printf("%d ",a[stk[i]].id);else printf("%d\n",a[stk[i]].id);
    }
}
