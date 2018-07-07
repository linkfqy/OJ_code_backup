#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=150005;
int n,lst,ans;
struct data{
	int t,tt;
	bool operator<(const data&b)const{
		return tt<b.tt;
	}
}a[maxn];
priority_queue<int> Q;
inline int red(){
	int tot=0;char ch=getchar();
	while (ch<'0'||'9'<ch) ch=getchar();
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot;
}
int main(){
	n=red();lst=0;
	for (int i=1;i<=n;i++) a[i].t=red(),a[i].tt=red();
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)
	 if (lst+a[i].t<=a[i].tt) lst+=a[i].t,Q.push(a[i].t),ans++;else
	  if (Q.top()>a[i].t) lst=lst-Q.top()+a[i].t,Q.pop(),Q.push(a[i].t);
	printf("%d",ans);
	return 0;
}
