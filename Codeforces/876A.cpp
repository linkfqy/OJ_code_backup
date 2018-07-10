#include<cstdio>

int n,a[3],ans;
int main(){
	scanf("%d%d%d%d",&n,&a[0],&a[1],&a[2]);
	int now=0;
	for (int i=1;i<n;i++){
		if (a[now]<a[(now+1)%3]) ans+=a[now],now=(now+2)%3;else
		 ans+=a[(now+1)%3],now=(now+1)%3;
	}
	printf("%d",ans);
	return 0;
} 
