#include<cstdio>
#include<cstring>
const int maxn=505,maxe=10005;
int n,e,con[maxn],ans;
int son[maxe],nxt[maxe],lnk[maxn],tot;
bool vis[maxn];
inline int red(){
	int tot=0;char ch=getchar();
	while (ch<'0'||'9'<ch) ch=getchar();
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot;
}
void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
bool fnd(int x){
	for (int j=lnk[x];j;j=nxt[j])
	 if (!vis[son[j]]){
	 	vis[son[j]]=1;
	 	if (!con[son[j]]||fnd(con[son[j]])){
	 		con[son[j]]=x;return 1;
	 	}
	 }
	return 0;
}
int main(){
	n=red(),e=red();
	for (int i=1;i<=e;i++) add(red(),red());
	for (int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		ans+=fnd(i);
	}
	printf("%d",ans);
	return 0;
}













/*
咳咳……这里就讲下如何看出二分图匹配的好了
对于一个陨石的坐标(x,y)我们可以理解为：
轰炸x行或y列都可以让这个陨石消失
那么如果把行和列看做两个集合，每个陨石(x,y)都是x连向y的边 
如果我们轰炸第y列，那么y列上所有的陨石都会消失，不必再去处理 
类似地， 若已经选择x~y这条边，那么任何与y相连的边都不需再处理（此时可以理解为轰炸了第y列） 
这不就完成了一次匹配吗？行和列构成的两个集合不就是二分图吗？
我们的目标就是把所有陨石消灭，且使用武器的次数最少
对应二分图，就是B点集中，所有有边相连的点都必须选一条边（一条就够了！）来匹配 
那么妥妥的用hungary 
*/
