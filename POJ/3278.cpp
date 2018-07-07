#include<cstdio>
const int maxn=300005;
int stt,gl,que[maxn],f[maxn];
bool vis[maxn];
bool check(int x){
	return 0<=x&&x<=300000&&!vis[x];
}
void bfs(){
	int hed=0,til=1;
	que[1]=stt;vis[stt]=1;
	if (stt==gl) {printf("0");return;}
	while (hed!=til){
		int x=que[++hed];
		if (check(x+1)) que[++til]=x+1,vis[x+1]=1,f[x+1]=f[x]+1;
		if (que[til]==gl) {printf("%d",f[que[til]]);break;}
		if (check(x-1)) que[++til]=x-1,vis[x-1]=1,f[x-1]=f[x]+1;
		if (que[til]==gl) {printf("%d",f[que[til]]);break;}
		if (check(x*2)) que[++til]=x*2,vis[x*2]=1,f[x*2]=f[x]+1;
		if (que[til]==gl) {printf("%d",f[que[til]]);break;}
	}
}
int main(){
	scanf("%d%d",&stt,&gl);
	bfs();
	return 0;
}

































/*
简单的BFS，但是要注意一下几点：
1.可以走到0点
2.题目中并未说明可以走到的上限是多少，但可以估算出不超过200000
3.注意N==K的情况（就是这里错了，查半天……） 
*/
