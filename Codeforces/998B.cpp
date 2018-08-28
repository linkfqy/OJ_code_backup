#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=105,maxv=105;
int n,N,V,a[maxn],w[maxn],f[maxn];
inline int Abs(int x) {return x>0?x:-x;}
int main(){
	scanf("%d%d",&n,&V);
	int s=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (i!=1&&s==0) w[++N]=Abs(a[i]-a[i-1]);
		if (a[i]&1) s++;else s--;
	}
	sort(w+1,w+1+N);
	int ans=0;
	for (int i=1;i<=N;i++)
	 if (w[i]<=V) V-=w[i],ans++;
	printf("%d",ans);
	return 0;
}
