#include<cstdio>

const int maxn=1505,maxs=maxn*maxn;
int n,N,q,fa[maxs];
inline int id(int x,int y) {return (x-1)*(n-1)+y;}
inline int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int main(){
	scanf("%d%d",&n,&q); N=(n-1)*(n-1);
	for (int i=0;i<=N;i++) fa[i]=i;
	int t=0;
	while (q--){
		char s[2][5];int x[2],y[2],xx,yy;
		scanf("%d%d%s%d%d%s",&x[0],&y[0],s[0],&x[1],&y[1],s[1]);
		if (s[t][0]=='N') xx=x[t]-1,yy=y[t];else xx=x[t],yy=y[t]-1;
		int idx,idy;
		if (xx<1||yy<1) idx=0;else idx=id(xx,yy);
		if (x[t]>=n||y[t]>=n) idy=0;else idy=id(x[t],y[t]);
		t=(getfa(idx)==getfa(idy));fa[getfa(idx)]=getfa(idy);
		puts(t?"NIE":"TAK");
	}
	return 0;
}
