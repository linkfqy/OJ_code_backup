#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100005;
int n,m,M,a[maxn],b[maxn],c[maxn],num[maxn];
bool calc(int x){
	for (int i=x+1;i<=M;i++)
	 if (num[i]) return num[x]+=c[i]/c[x],num[i]--,1;
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) scanf("%d",&b[i]);
	sort(b+1,b+1+m);
	for (int i=1;i<=m;i++)
	 if (b[i]!=b[i-1]) c[++M]=b[i];
	for (int i=1;i<=n;i++){
		int x=a[i];
		for (int j=M;j>=1;j--) num[j]+=x/c[j],x%=c[j];
	}
	for (int i=1,j=1;i<=m;i++){
		while (b[i]>c[j]) j++;
		if (num[j]) num[j]--;else
		if (calc(j)) num[j]--;else return printf("%d",i-1),0;
	}
	printf("%d",m);
	return 0;
}
