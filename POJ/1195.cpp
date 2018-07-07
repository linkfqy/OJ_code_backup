#include<cstdio>
#define lowbit(x) ((x)&-(x))
const int maxn=1030;
int tre[maxn][maxn],n;
inline int red(){
	int tot=0,f=1;char ch=getchar();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=getchar();}
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot*f;
}
void ist(int x,int y,int w){
	for (int i=x;i<=n;i+=lowbit(i))
	 for (int j=y;j<=n;j+=lowbit(j))
	  tre[i][j]+=w;
}
int qry(int x,int y){
	int res=0;
	for (int i=x;i;i-=lowbit(i))
	 for (int j=y;j;j-=lowbit(j))
	  res+=tre[i][j];
	return res;
}
int main(){
	red();n=red();
	while (1){
		int t=red();
		if (t==3) return 0;
		if (t==1){
			int x=red()+1,y=red()+1,w=red();
			ist(x,y,w);
		}else{
			int x=red()+1,y=red()+1,xx=red()+1,yy=red()+1;
			printf("%d\n",qry(xx,yy)-qry(xx,y-1)-qry(x-1,yy)+qry(x-1,y-1));
		}
	}
}
