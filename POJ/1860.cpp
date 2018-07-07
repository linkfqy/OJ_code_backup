#include<cstdio>
#include<cstdlib>
#include<cstring>
const int maxn=105,maxe=205;
int n,e,stt,times[maxn],que[maxn];
int son[maxe],lnk[maxn],nxt[maxe],tot;
double r[maxe],c[maxe],dst[maxn];
double sttw;
bool vis[maxn];
void add(int x,int y,double ri,double ci){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;r[tot]=ri;c[tot]=ci;
}
void print(){
	printf("YES");
	exit(0);
}
void spfa(){
	memset(dst,254,sizeof(dst));
	int hed=0,til=1;
	que[1]=stt;dst[stt]=sttw;times[stt]=1;
	while (hed!=til){
		int x=que[hed=(hed+1)%maxn];
		vis[x]=0;
		for (int j=lnk[x];j;j=nxt[j])
		 if (dst[son[j]]<(dst[x]-c[j])*r[j]){
		 	dst[son[j]]=(dst[x]-c[j])*r[j];
		 	if (!vis[son[j]]){
		 		vis[son[j]]=1,
		 		que[til=(til+1)%maxn]=son[j],
		 		times[son[j]]++;
		 		if (times[son[j]]==n) print();
		 	}
		 }
	}
}
int main(){
	scanf("%d%d%d%lf",&n,&e,&stt,&sttw);
	for (int i=1;i<=e;i++){
		int x,y;double r,c;
		scanf("%d%d%lf%lf",&x,&y,&r,&c);
		add(x,y,r,c);scanf("%lf%lf",&r,&c);
		add(y,x,r,c);
	}
	spfa();
	printf("NO");
	return 0;
}












/*
如果起点所在联通块内有正权回路，则可以赚钱
SPFA判环方法：若某个点入队N次，则有正权回路 
方法2：每次修正dst时，修正dep[son[j]]=dep[x]+1
若某个点dep大于n，则有环 
*/
