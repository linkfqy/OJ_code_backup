#include<cstdio>
const int maxn=1005;
int n,d,q,x[maxn],y[maxn],fa[maxn];
bool vis[maxn];
inline int red(){
	int tot=0;char ch=getchar();
	while (ch<'0'||'9'<ch) ch=getchar();
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot;
}
inline char fstchar(){
	char ch=getchar();
	while (ch!='O'&&ch!='S'){
		if (ch==EOF) return 0;
		ch=getchar();
	}
	return ch;
}
int getfa(int x){
	if (fa[x]==x) return x;
	return fa[x]=getfa(fa[x]);
}
void marge(int x,int y){
	x=getfa(x);y=getfa(y);
	if (x==y) return;
	fa[x]=y;
}
int getdst(int i,int j){
	return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}
int main(){
	n=red(),d=red();d=d*d;
	for (int i=1;i<=n;i++) x[i]=red(),y[i]=red(),fa[i]=i;
	for (char c=fstchar();c;c=fstchar())
	 if (c=='O'){
	 	int x=red();vis[x]=1;
	 	for (int i=1;i<=n;i++)
		 if (vis[i]&&getdst(x,i)<=d) marge(x,i);
	 }else
	  if (getfa(red())==getfa(red())) printf("SUCCESS\n");else printf("FAIL\n");
	return 0;
}
