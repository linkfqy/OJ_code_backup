#include<cstdio>
const int maxn=100005;
char a[maxn],b[maxn];
int main(){
	while (scanf("%s%s",a,b)==2){
		bool suc=1;
		for (int i=0,j=0;a[i]&&b[j];i++,j++){
			while (b[j]&&b[j]!=a[i]) j++;
			if (!b[j]) {suc=0;break;}
		}
		if (suc) printf("Yes\n");else printf("No\n");
	}
	return 0;
}
