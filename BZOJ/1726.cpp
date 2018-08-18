#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;

const int maxn=5005,maxe=200005;
int n,e,dst[maxn];
bool vis[maxn];
int tot,son[maxe],nxt[maxe],lnk[maxn],w[maxe];
inline void add(int x,int y,int z){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=z;
}
void DIJ(){
	cl(dst,63);
	dst[n]=0;
	for (int i=1;i<=n;i++){
		int k,MIN=0x3f3f3f3f;
		for (int j=1;j<=n;j++)
		 if (!vis[j]&&dst[j]<MIN) MIN=dst[k=j];
		vis[k]=1;
		for (int j=lnk[k];j;j=nxt[j])
		 dst[son[j]]=min(dst[son[j]],dst[k]+w[j]);
	}
}
struct data{
	int id,x;
	data () {}
	data (int _id,int _x):id(_id),x(_x) {}
	inline bool operator<(const data&b)const {return x+dst[id]>b.x+dst[b.id];}
};
priority_queue<data> Q;
int Astar(){
	Q.push(data(1,0));
	while (!Q.empty()){
		data k=Q.top();Q.pop();
		if (k.id==n&&k.x>dst[1]) return k.x;
		for (int j=lnk[k.id];j;j=nxt[j])
		 Q.push(data(son[j],k.x+w[j]));
	}
}
int main(){
	scanf("%d%d",&n,&e);
	for (int i=1,x,y,z;i<=e;i++) scanf("%d%d%d",&x,&y,&z),add(x,y,z),add(y,x,z);
	DIJ();
	printf("%d",Astar());
	return 0;
}
