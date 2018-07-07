#include<cstdio>
#include<cstring>
const int maxn=10;
int tar,ans,times;
char s[maxn];
bool vis[maxn],b[maxn];
void dfs(int stp){
	if (!s[stp+1]){
		int sum=0,res=0;
		for (int i=0;s[i];i++){
			sum=sum*10+s[i]-48;
			if (vis[i]||!s[i+1]) res+=sum,sum=0;
		}
		if (res<=tar){
		 if (res>ans) ans=res,times=1,memcpy(b,vis,sizeof(b));else
		 if (res==ans) times++;
		}
		return;
	}
	vis[stp]=1;dfs(stp+1);
	vis[stp]=0;dfs(stp+1);
}
int main(){
	for (scanf("%d%s",&tar,s);tar;scanf("%d%s",&tar,s)){
		memset(vis,0,sizeof(vis));
		ans=-1;times=0;dfs(0);
		if (ans<0) printf("error\n");else
		if (times>1) printf("rejected\n");else{
			printf("%d ",ans);
			for (int i=0;s[i];i++){
				putchar(s[i]);
				if (b[i]) putchar(32);
			}
			putchar(10);
		}
	}
	return 0;
}
