#include<cstdio>

const int maxn=250005;
int n,stk[maxn];
int main(){
	scanf("%d",&n);
	int ans=0;
	for (int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		while (stk[0]&&stk[stk[0]]>=y){
			if (stk[stk[0]]==y) ans++;
			stk[0]--;
		}
		stk[++stk[0]]=y;
	}
	printf("%d",n-ans);
	return 0;
}
