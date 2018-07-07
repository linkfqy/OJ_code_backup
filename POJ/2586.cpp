#include<cstdio>
int s,d;
int main(){
	while (scanf("%d%d",&s,&d)==2){
		if (d>4*s)
		 if (10*s-2*d<0) {printf("Deficit\n");continue;} else printf("%d\n",10*s-2*d);
		else
		if (2*d>3*s)
		 if (8*s-4*d<0) {printf("Deficit\n");continue;} else printf("%d\n",8*s-4*d);
		else
		if (3*d>2*s)
		 if (6*s-6*d<0) {printf("Deficit\n");continue;} else printf("%d\n",6*s-6*d);
		else
		if (4*d>s)
		 if (3*s-9*d<0) {printf("Deficit\n");continue;} else printf("%d\n",3*s-9*d);
		else printf("Deficit\n");
	}
	return 0;
}








/*
如果安排一次报告中每个月的盈亏，我们肯定会把亏的(d)放在后面，因为这样可以尽量使d被共用多次
那么就可以按照以下来分类讨论：
    盈亏        条件    答案
ssssd ssssd ss  d>4s   10s-2d
sssdd sssdd ss  2d>3s  8s-4d
ssddd ssddd ss  3d>2s  6s-6d
sdddd sdddd sd  4d>s   3s-9d
ddddd ddddd dd  4d<s   Deficit
*/
