#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
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

const int maxn=100005;
int n,k,a[maxn],b[maxn],hsh[maxn];
bool check(int mid){
	memset(hsh,0,sizeof(hsh));
	ll res=0;hsh[a[1]]++;
	for (int i=1,j=1;i<=n;hsh[a[i++]]--){
		while (j<=n&&hsh[a[j]]<mid) hsh[a[++j]]++;
		res+=n-j+1;
	}
	return res>=k;
}
int main(){
	n=red(),k=red();
	for (int i=1;i<=n;i++) b[i]=a[i]=red();
	sort(b+1,b+1+n);
	int m=unique(b+1,b+1+n)-b-1;
	for (int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+1+m,a[i])-b;
	int l=1,r=n,ans=1;
	while (l<=r){
		int mid=l+r>>1;
		if (check(mid)) l=mid+1,ans=mid;else r=mid-1;
	}
	printf("%d",ans);
	return 0;
}
