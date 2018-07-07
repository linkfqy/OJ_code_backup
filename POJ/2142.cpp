#include<cstdio>
#include<algorithm>
using namespace std;
int a,b,d;
struct ha{
	int x,y;
	ha set(int a,int b){return (ha){x+a,y+b};}
	bool operator<(const ha&t)const{
		if (x<0||y<0) return 0;
		if (t.x<0||t.y<0) return 1;
		return x+y<t.x+t.y||x+y==t.x+t.y&&a*x+b*y<t.x*a+t.y*b;
	}
}n1,n2,n3;
int exgcd(int a,int b,int&x,int&y){
	if (!b) {x=1,y=0;return a;}
	int d=exgcd(b,a%b,x,y),x0=x;
	x=y;
	y=x0-a/b*y;
	return d;
}
void solve(int a,int b,int c,ha&n){
	n=(ha){1000000,1000000};
	int x0,y0,d=exgcd(a,b,x0,y0);
	if (c%d) return;
	int a1=a/d,b1=b/d,c1=c/d;
	x0*=c1;y0*=c1;
	int s=-x0/b1-1,e=y0/a1+1;
	for (int i=s;i<=e;i++)
	 n=min(n,(ha){x0+b1*i,y0-a1*i});
}
int main(){
	scanf("%d%d%d",&a,&b,&d);
	while (a){
		solve(a,b,d,n1);
		solve(a,-b,d,n2);
		solve(-a,b,d,n3);
		ha ans=min(n1,min(n2,n3));
		printf("%d %d\n",ans.x,ans.y);
		scanf("%d%d%d",&a,&b,&d);
	}
	return 0;
}




/*
共有三种情况：
ax+by=d
ax-by=d
by-ax=d
分别套扩展欧几里得算法即可
值得注意的是如何取到合适的x,y值
题目中隐含的限制是x>=0，y>=0。似乎很难控制
观察得到方程ax+by=d的所有解的公式：
x=x0+b1*i
y=y0-a1*i
可以将其看做是两个一次函数，i是自变量，x,y是应变量，x0是截距，a1,b1是斜率
则x>=0，y>=0的条件可以看做两个一次函数与x轴的交点，将这两个交点作为枚举范围的两个端点，进行变量i的枚举即可 
*/
