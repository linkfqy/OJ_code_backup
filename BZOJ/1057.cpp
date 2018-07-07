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

const int maxn=2005;
int n,m,ans1,ans2;
bool a[maxn][maxn];
int up[maxn],lft[maxn],rit[maxn];
void work(){
	for (int j=0;j<=m+1;j++) up[j]=lft[j]=0,rit[j]=m+1;
	for (int i=1;i<=n;i++){
		int lst=1;
		for (int j=1;j<=m;j++)
		 if (a[i][j]) up[j]=lft[j]=0,lst=j+1;
		 else up[j]++,lft[j]=max(lst,lft[j]);
		lst=m;
		for (int j=m;j;j--)
		 if (a[i][j]) rit[j]=m+1,lst=j-1;
		 else{
		 	rit[j]=min(lst,rit[j]);
		 	int h=up[j],w=rit[j]-lft[j]+1;
		 	ans1=max(ans1,min(h,w)*min(h,w));
		 	ans2=max(ans2,h*w);
		 }
	}
}
int main(){
	n=red(),m=red();
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	  a[i][j]=red()^((i+j)&1);
	work();
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	  a[i][j]^=1;
	work();
	printf("%d\n%d",ans1,ans2);
	return 0;
}
