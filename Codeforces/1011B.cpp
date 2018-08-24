#include<cstdio>

const int maxn=105;
int n,m,num[maxn];
bool check(int day){
	int tot=0;
	for (int i=1;i<=100;i++) tot+=num[i]/day;
	return tot>=n;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1,x;i<=m;i++) scanf("%d",&x),num[x]++;
	int l=1,r=10000,ans=0;
	while (l<=r){
		int mid=l+r>>1;
		if (check(mid)) ans=mid,l=mid+1;else r=mid-1;
	}
	printf("%d",ans);
	return 0;
}
