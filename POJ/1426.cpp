#include<cstdio>
#define LL long long
int n;
bool suc;
void dfs(LL x,int stp){
	if (suc||stp>19) return;
	if (x%n==0){printf("%lld\n",x);suc=1;return;}
	dfs(x*10,stp+1);dfs(x*10+1,stp+1);
}
int main(){
	for (scanf("%d",&n);n;scanf("%d",&n))
	 suc=0,dfs(1,1);
	return 0;
}
