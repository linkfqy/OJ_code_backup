#include<cstdio>

const int maxn=100005;
int n,K;
bool qry(int x,int y){
	if (y>n) return 1;
	printf("1 %d %d\n",x,y);fflush(stdout);
	char s[5];
	scanf("%s",s);
	return s[0]=='T';
}
int work(int l,int r){
	if (l<1||r>n) return 0;
	int res=0;
	while (l<=r){
		int mid=l+r>>1;
		if (qry(mid,mid+1)) res=mid,r=mid-1;else l=mid+1;
	}
	return res;
}
int main(){
	scanf("%d%d",&n,&K);
	int x,y;
	x=work(1,n); y=work(1,x-1);
	if (!y) y=work(x+1,n);
	printf("2 %d %d\n",x,y);fflush(stdout);
	return 0;
}
