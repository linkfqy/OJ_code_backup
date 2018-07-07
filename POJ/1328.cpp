#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1005;
int n,r,tst=0;
struct ha{
	double s,t;
	bool operator<(const ha&b)const{
		return s<b.s;
	}
}a[maxn];
inline int red(){
	int tot=0,f=1;char ch=getchar();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=getchar();}
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot*f;
}
int main(){
	n=red(),r=red();
	while (n){
		bool im=0;tst++;
		for (int i=1;i<=n;i++){
			int x=red(),y=red();
			if (y>r) im=1;
			double l=sqrt((double)r*r-y*y);
			a[i].s=x-l;a[i].t=x+l;
		}
		if (im) {printf("Case %d: -1\n",tst);n=red(),r=red();continue;}
		sort(a+1,a+1+n);//for (int i=1;i<=n;i++) printf("%.2lf %.2lf\n",a[i].s,a[i].t);
		int ans=1;double hed=a[1].s,til=a[1].t;
		for (int i=2;i<=n;i++)
		 if (a[i].s>til) ans++,hed=a[i].s,til=a[i].t;else
		  hed=a[i].s,til=min(a[i].t,til);
		printf("Case %d: %d\n",tst,ans);
		n=red(),r=red();
	}
	return 0;
}









/*
以某个岛为圆心，扫描距离r为半径，作圆。则被该圆覆盖之处就可以安装雷达。
那么对于岛(x,y)，将雷达放在x-sqrt(r^2-y^2)~x+sqrt(r^2-y^2)处可以将其覆盖
问题就转化成扫描线段问题，除去重复的线段即可。 
*/
