#include<cstdio>
#include<cmath>
using namespace std;
const double dat=1e-7;
int main(){
	double n,p;
	while (scanf("%lf%lf",&n,&p)==2){
		int x=pow(p,1/n)+dat;
		printf("%d\n",x);
	}
	return 0;
}
