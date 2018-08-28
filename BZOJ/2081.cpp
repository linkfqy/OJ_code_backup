#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;

const int maxn=200005,tt=19260817;
int n,a[maxn],ans[maxn]; ull hsh[2][maxn],pw[maxn];
inline ull get(int d,int l,int r){
	return hsh[d][r]-hsh[d][l-1]*pw[r-l+1];
}
set<ull> S;
int calc(int k){
	S.clear(); int res=0;
	for (int i=k;i<=n;i+=k){
		ull t1=get(0,i-k+1,i),t2=get(1,n-i+1,n-i+k);
		if (S.count(t1)||S.count(t2)) continue;
		res++; S.insert(t1);
	}
	return res;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	pw[0]=1;
	for (int i=1;i<=n;i++)
	 hsh[0][i]=hsh[0][i-1]*tt+a[i],pw[i]=pw[i-1]*tt,
	 hsh[1][i]=hsh[1][i-1]*tt+a[n-i+1];
	int MAX=0;
	for (int k=1;k<=n;k++){
		int t=calc(k);
		if (MAX<t) MAX=t,ans[ans[0]=1]=k;else
		if (MAX==t) ans[++ans[0]]=k;
	}
	printf("%d %d\n",MAX,ans[0]);
	for (int i=1;i<=ans[0];i++) printf("%d ",ans[i]);
	return 0;
}
