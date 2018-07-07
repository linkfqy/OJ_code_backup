#include<cstdio>
typedef long long ll;

const int maxn=55;
int n,m,c[maxn];
bool check(int x){
	ll tot=0;
	for (int i=1;i<=n;i++)
	 if (c[i]<x) tot+=x-c[i];
	return tot<=x&&tot<=m;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	int L=0,R=1e9,ans;
	while (L<=R){
		int mid=L+R>>1;
		if (check(mid)) ans=mid,L=mid+1;else R=mid-1;
	}
	printf("%d",ans);
	return 0;
}
