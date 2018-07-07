#include<cstdio>
#define LL long long
const int p[11]={10,2,3,5,7,11,13,17,19,23,29};
int n,ans,yz;
LL power(int a,int b){
	LL w=a,ans=1;
	while (b){
		if (b&1) ans*=w;
		w=w*w;
		b>>=1;
	}
	return ans;
}
void dfs(LL now,int stp,int lst,int num){
	if (stp>10){
		if (num>yz||yz==num&&ans>now) ans=now,yz=num;
		return;
	}
	for (int i=0;i<=lst;i++)
	 if (now*power(p[stp],i)<=n)
	  dfs(now*power(p[stp],i),stp+1,i,num*(i+1));else break;
}
int main(){
	scanf("%d",&n);
	dfs(1,1,32,1);
	printf("%d",ans);
	return 0;
}
