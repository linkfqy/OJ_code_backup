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
��Ŀ��������һ�䣺��where each soldier can see by looking lengthwise the line at least one of the line's extremity (left or right)��
�����������Ҫʹÿ��ʿ���������ٿ�������ľ�ͷ֮һ����ʿ������һ��ʱ��������������˶����������ܿ�����ͷ�� 
����򵥵��������/����ʵ�Ǵ�ģ������롰�ϳ����Ρ��е����ƣ������γ�һ��ɽ�ζ���
�������в�֮ͬ�����ڶ������ߴ���������������ͬ�߶ȵ�ʿ�� 
*/
