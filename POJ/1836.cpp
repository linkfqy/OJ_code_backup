#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1005;
int n,f1[maxn],f2[maxn],ans;
double a[maxn];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lf",&a[i]),f1[i]=f2[i]=1;
	for (int i=1;i<=n;i++)
	 for (int j=1;j<i;j++)
	  if (a[j]<a[i]&&f1[j]+1>f1[i]) f1[i]=f1[j]+1;
	for (int i=n;i>=1;i--)
	 for (int j=n;j>i;j--)
	  if (a[j]<a[i]&&f2[j]+1>f2[i]) f2[i]=f2[j]+1;
	ans=max(f1[n],f2[1]);
	int Max=0;
	for (int i=1;i<n;i++)
	 Max=max(Max,f1[i]),
	 ans=max(ans,Max+f2[i+1]);
	printf("%d",n-ans);
	return 0;
}




















/*
题目中有这样一句：“where each soldier can see by looking lengthwise the line at least one of the line's extremity (left or right)”
翻译过来就是要使每个士兵都能至少看到队伍的尽头之一（当士兵看向一边时，这个方向所有人都比他矮才能看到尽头） 
如果简单地理解成最长升/降其实是错的，本题与“合唱队形”有点相似，可以形成一个山形队列
但是又有不同之处：在队伍的最高处，可以由两个相同高度的士兵 
*/
