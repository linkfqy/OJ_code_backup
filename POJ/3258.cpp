#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=50005;
int n,m,l,a[maxn],ans=-1;
bool vis[maxn];
inline int red(){
	int tot=0;char ch=getchar();
	while (ch<'0'||'9'<ch) ch=getchar();
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot;
}
bool check(int x){
	memset(vis,0,sizeof(vis));
	for (int i=1,j=2;i<=n;){
		while (j<=n&&a[j]-a[i]<x) vis[j]=1,j++;
		i=j;j++;
		if (j>n) break;
	}
	int tot=0;
	for (int i=1;i<=n;i++) tot+=vis[i];
	return tot<=m;
}
int main(){
	l=red(),n=red(),m=red();
	for (int i=1;i<=n;i++) a[i]=red();
	a[++n]=0;a[++n]=l;sort(a+1,a+1+n);
	int L=1,R=l;
	while (L<=R){
		int mid=L+R>>1;
		if (check(mid)) ans=mid,L=mid+1;else R=mid-1;
	}
	printf("%d",ans);
	return 0;
}
