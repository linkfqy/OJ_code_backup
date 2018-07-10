#include<cstdio>
#include<algorithm>
using namespace std;
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

int n,k,a[100005],f[100005];
int main(){
	n=red(),k=red();
	if (k==1){
		int Min=0x3f3f3f3f;
		for (int i=1;i<=n;i++) Min=min(Min,red());
		printf("%d",Min);
	}else
	if (k==2){
		int Min=f[0]=0x3f3f3f3f,ans=0x80000000;
		for (int i=1;i<=n;i++) a[i]=red(),f[i]=min(f[i-1],a[i]);
		for (int i=n;i;i--){
			if (i<n) ans=max(ans,max(Min,f[i]));
			Min=min(Min,a[i]);
		}
		printf("%d",ans);
	}else
	if (k>=3){
		int Max=0x80000000;
		for (int i=1;i<=n;i++) Max=max(Max,red());
		printf("%d",Max);
	}
	return 0;
}
