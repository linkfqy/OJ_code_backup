#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef long long ll;
inline char nc(){
	static char buf[100000],*l=buf,*r=buf;
	return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++;
}
inline int red(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
	return res*f;
}

const int maxn=505,maxnn=250005,maxe=1000005,p[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int n,a[maxn][maxn][4],S,T;
int tot,son[maxe],nxt[maxe],lnk[maxnn],w[maxe];
inline void add(int x,int y,int z){
	son[++tot]=y,nxt[tot]=lnk[x],lnk[x]=tot,w[tot]=z;
}
#define getid(x,y) (((x)-1)*n+(y))
ll dst[maxnn];
struct data{
	int x;ll w;
	data () {}
	data (int _x,ll _w) {x=_x;w=_w;}
	bool operator<(const data&b)const {return w>b.w;}
};
priority_queue<data> H;
void DIJ(){
	cl(dst,63);
	H.push(data(S,0));dst[S]=0;
	while (!H.empty()){
		if (H.top().w>dst[H.top().x]) {H.pop();continue;}
		int k=H.top().x; H.pop();
		for (int j=lnk[k];j;j=nxt[j])
			if (dst[son[j]]>dst[k]+w[j])
				dst[son[j]]=dst[k]+w[j],H.push(data(son[j],dst[son[j]]));
	}
}
int main(){
	n=red();S=n*n+1;T=S+1;
	for (int i=0;i<=n;i++)
		for (int j=1;j<=n;j++) a[i][j][0]=red();
	for (int i=1;i<=n;i++)
		for (int j=0;j<=n;j++) a[i][j][1]=red();
	for (int i=0;i<=n;i++)
		for (int j=1;j<=n;j++) a[i][j][2]=red();
	for (int i=1;i<=n;i++)
		for (int j=0;j<=n;j++) a[i][j][3]=red();
	//make graph:
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int t=0;t<4;t++){
				int x=i+p[t][0],y=j+p[t][1],w;
				if (y<1) {add(S,getid(i,j),a[x][y][(t+2)%4]);continue;}
				if (x>n) {add(S,getid(i,j),a[i][j][(t+2)%4]);continue;}
				if (t==1||t==2) w=a[i][j][t];else w=a[x][y][t];
				if (x<1||y>n) add(getid(i,j),T,w);else
				add(getid(i,j),getid(x,y),w);
			}
	DIJ();
	printf("%lld",dst[T]);
	return 0;
}
