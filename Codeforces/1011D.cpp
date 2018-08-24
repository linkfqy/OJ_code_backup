#include<cstdio>
#include<cstdlib>

int n,m;
bool fake[50];
inline int ask(int x){
	printf("%d\n",x);fflush(stdout);
	scanf("%d",&x);return x;
}
int main(){
	scanf("%d%d",&m,&n);
	for (int i=1;i<=n;i++){
		int x=ask(1); if (x==0) return 0;
		fake[i]=(x<0);
	}
	int l=2,r=m,times=0;
	while (l<=r){ times=times%n+1;
		int mid=l+r>>1,x=ask(mid);
		if (fake[times]) x=-x;
		if (x==0) return 0;
		if (x>0) l=mid+1;else r=mid-1;
	}
	return 0;
}
