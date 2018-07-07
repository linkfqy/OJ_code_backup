#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=25;
const double eps=1e-4;
int n;
struct point{
	double x,y;
	point(double x=0,double y=0):x(x),y(y) {}
}a[maxn],b[maxn];
struct line{
	double k,b;
	void get(point x,point y){
		k=(x.y-y.y)/(x.x-y.x);
		b=x.y-k*x.x;
	}
	double gety(double x){return k*x+b;}
}l[45];
int dcmp(double a,double b){
	if (fabs(a-b)<eps) return 0;
	if (a<b) return -1;
	return  1;
}
double intersect(line a,line b){
	return (b.b-a.b)/(a.k-b.k);
}
int main(){
	scanf("%d",&n);
	while (n){
		for (int i=1;i<=n;i++){
			double x,y;scanf("%lf%lf",&x,&y);
			a[i]=point(x,y);b[i]=point(x,y-1);
			if (i>1){
				l[i*2-1].get(a[i],a[i-1]);
				l[i*2].get(b[i],b[i-1]);
			}
		}
		double ans=-(1e100);bool flg=0;
		for (int i=1;i<=n&&!flg;i++)
		 for (int j=1;j<=n&&!flg;j++)
		  if (i!=j){
		  	line now;now.get(a[i],b[j]);int k;
		  	for (k=1;k<=n;k++){
		  		double y=now.gety(a[k].x);
		  		if (!(dcmp(b[k].y,y)<=0&&dcmp(y,a[k].y)<=0)) break;
			}
			if (k>n) {flg=1;break;}
			if (k<=max(i,j)) continue;
			ans=max(ans,max(intersect(now,l[k*2-1]),intersect(now,l[k*2])));
		  }
		if (flg) printf("Through all the pipe.\n");else printf("%.2f\n",ans);
		scanf("%d",&n);
	}
	return 0;
}


/*
����������£�����һ���������������߹��ɵĹܵ������±ھ���͸���������⣩��������Ƿ��ܴ����ܵ����������Զ�ܵ��ľ��롣

��ô������һ�����ۣ����ŵ���·һ�������϶˵㡢�¶˵����ٸ�һ������Ϊ�����߲������κζ˵㣬����ȫ������ת��ƽ������ʹ����ø�Զ����ô�����˵�����ƶ��ļ�����������п������š� 
���ǿ���ֱ��ö�����������˵㣬��һ��ֱ�ߣ������ж��Ƿ񴩹�ÿ����ļ�������ǰ�x������ͬ��һ�Զ˵�֮����߶γ�Ϊ��������������м�������������Ҫ������Զ���� 
*/
