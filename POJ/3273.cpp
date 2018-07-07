#include<cstdio>
const int maxn=100005;
int n,m,a[maxn],ans;
inline int red(){
	int tot=0;char ch=getchar();
	while (ch<'0'||'9'<ch) ch=getchar();
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot;
}
bool check(int x){
	int sum=0,num=1;
	for (int i=1;i<=n;i++){
		if (a[i]>x) return 0;
		if (sum+a[i]>x) sum=a[i],num++;else sum+=a[i];
	}
	return num<=m;
}
int main(){
	n=red(),m=red();
	int L=1,R=0;
	for (int i=1;i<=n;i++) a[i]=red(),R+=a[i];
	while (L<=R){
		int mid=L+R>>1;
		if (check(mid)) ans=mid,R=mid-1;else L=mid+1;
	}
	printf("%d",ans);
	return 0;
}
