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
	while ('0'<=ch&&ch<='9') res=(res<<3)+(res<<1)+ch-48,ch=nc();
	return res*f;
}

const int maxn=1005;
int n,m,K,a[maxn][maxn],mx[maxn][maxn],mn[maxn][maxn];
int quem[maxn],hedm,tilm,quen[maxn],hedn,tiln;
int main(){
	n=red(),m=red();K=red();
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++) a[i][j]=red();
	for (int i=1;i<=n;i++){
		hedm=hedn=1,tilm=tiln=0;
		for (int j=1;j<=m;j++){
			while (hedm<=tilm&&quem[hedm]<j-K+1) hedm++;
			while (hedn<=tiln&&quen[hedn]<j-K+1) hedn++;
			while (hedm<=tilm&&a[i][quem[tilm]]<=a[i][j]) tilm--;
			while (hedn<=tiln&&a[i][quen[tiln]]>=a[i][j]) tiln--;
			quem[++tilm]=quen[++tiln]=j;
			mx[i][j]=a[i][quem[hedm]];mn[i][j]=a[i][quen[hedn]];
		}
	}
	int ans=0x3f3f3f3f;
	for (int j=K;j<=m;j++){
		hedm=hedn=1,tilm=tiln=0;
		for (int i=1;i<=n;i++){
			while (hedm<=tilm&&quem[hedm]<i-K+1) hedm++;
			while (hedn<=tiln&&quen[hedn]<i-K+1) hedn++;
			while (hedm<=tilm&&mx[quem[tilm]][j]<=mx[i][j]) tilm--;
			while (hedn<=tiln&&mn[quen[tiln]][j]>=mn[i][j]) tiln--;
			quem[++tilm]=quen[++tiln]=i;
			if (i>=K) ans=min(ans,mx[quem[hedm]][j]-mn[quen[hedn]][j]);
		}
	}
	printf("%d",ans);
	return 0;
}
