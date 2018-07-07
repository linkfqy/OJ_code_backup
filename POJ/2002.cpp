#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1005;
int n;
struct ha{
	int x,y;
	bool operator<(const ha&b)const{
		return x<b.x||x==b.x&&y<b.y;
	}
	bool operator==(const ha&b)const{
		return x==b.x&&y==b.y;
	}
}a[maxn];
inline int red(){
	int tot=0,f=1;char ch=getchar();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=getchar();}
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot*f;
}
bool fnd(ha x){
	return (*lower_bound(a+1,a+1+n,x))==x;
}
int main(){
	for (n=red();n;n=red()){
		for (int i=1;i<=n;i++) a[i]=(ha){red(),red()};
		sort(a+1,a+1+n);
		int ans=0;
		for (int i=1;i<n;i++)
		 for (int j=i+1;j<=n;j++){
		 	int b=a[j].y-a[i].y-a[j].x+a[i].x;
		 	if (b&1) continue;else b>>=1;
		 	if (fnd((ha){a[i].x-b,a[j].y-b})&&fnd((ha){a[j].x+b,a[i].y+b})) ans++;
		 }
		printf("%d\n",ans>>1);
	}
	return 0;
}
