#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
inline char nc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int red(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
	return res*f;
}

const int maxn=50005,INF=0x3f3f3f3f;
int n,a[maxn],mx[maxn],mn[maxn];
LL ans,smx[maxn],smn[maxn];
void divide(int L,int R){
	if (L==R) return;
	int mid=L+R>>1;
	divide(L,mid);divide(mid+1,R);
	mx[mid]=0;mn[mid]=INF;
	smx[mid]=smn[mid]=0;
	for (int i=mid+1;i<=R;i++){
		mx[i]=max(mx[i-1],a[i]);mn[i]=min(mn[i-1],a[i]);
		smx[i]=smx[i-1]+mx[i];smn[i]=smn[i-1]+mn[i];
	}
	LL Max=0,Min=INF;
	for (int i=mid,jx=mid,jm=mid;i>=L;i--){
		Max=max(Max,(LL)a[i]);Min=min(Min,(LL)a[i]);
		while (jx<R&&mx[jx+1]<=Max) jx++;
		while (jm<R&&mn[jm+1]>=Min) jm++;
		ans+=Max*(jx-mid)+smx[R]-smx[jx]-Min*(jm-mid)-smn[R]+smn[jm];
	}
}
int main(){              
	n=red();
	for (int i=1;i<=n;i++) a[i]=red();
	divide(1,n);
	printf("%lld",ans);
	return 0;
}
