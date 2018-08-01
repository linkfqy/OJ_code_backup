#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int red(){
    int tot=0,f=1;char ch=getchar();
    while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=getchar();}
    while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
    return f*tot;
}

const int maxn=1e5+5,MOD=1e9+7,inv2=MOD+1>>1;
int q,h[maxn],ans[maxn];
void blocker(int n){
    int k=sqrt(n);
    for (int i=1;i<=n;i++) h[i]=(i-1)/k+1;
}
struct data{
    int l,r,id;
    bool operator<(const data&b)const{
        if (h[l]==h[b.l]) return r<b.r;
        return l<b.l;
    }
}que[maxn];
ll C,frac[maxn],inv[maxn];
ll power(ll a,int b){
    ll res=1,w=a;
    while (b){
        if (b&1) (res*=w)%=MOD;
        (w*=w)%=MOD;
        b>>=1;
    }
    return res;
}
inline ll c(int n,int m){
    if (n==m) return 1;
    return frac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
int main(){
    q=red(); blocker(q);
    for (int i=1;i<=q;i++) que[i].r=red(),que[i].l=red(),que[i].id=i;
    sort(que+1,que+1+q);
    C=1;
    frac[0]=1;for (int i=1;i<=1e5;i++) frac[i]=(frac[i-1]*i)%MOD;
    for (int i=0;i<=1e5;i++) inv[i]=power(frac[i],MOD-2);
    for (int i=1,L=0,R=0;i<=q;i++){
        while (R<que[i].r){
            C=(2*C%MOD-c(R++,L))%MOD;
        }
        while (R>que[i].r){
            C=(C+c(--R,L))%MOD*inv2%MOD;
        }
        while (L<que[i].l){
            C=(C+c(R,++L))%MOD;
        }
        while (L>que[i].l){
            C=(C-c(R,L--))%MOD;
        }
        ans[que[i].id]=C;
    }
    for (int i=1;i<=q;i++) printf("%d\n",(ans[i]+MOD)%MOD);
    return 0;
}
