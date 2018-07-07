#include<cstdio>
#include<cstring>
const int maxn=1005;
int n,q,tst,tre[maxn][maxn];
inline int red(){
	int tot=0;char ch=getchar();
	while (ch<'0'||'9'<ch) ch=getchar();
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot;
}
inline int lowbit(int x){
	return x&(-x);
}
inline void change(int x,int y,int w){
	for (int i=x;i<=n;i+=lowbit(i))
	 for (int j=y;j<=n;j+=lowbit(j))
	  tre[i][j]+=w;
}
inline int ask(int x,int y){
	int res=0;
	for (int i=x;i;i-=lowbit(i))
	 for (int j=y;j;j-=lowbit(j))
	  res+=tre[i][j];
	return res&1;
}
inline char fstchar(){
	char ch=getchar();
	while (ch!='C'&&ch!='Q') ch=getchar();
	return ch;
}
int main(){
	tst=red();
	while (tst--){
		memset(tre,0,sizeof(tre));
		n=red(),q=red();
		while (q--)
		 if (fstchar()=='C'){
		 	int x=red(),y=red(),xx=red(),yy=red();
		 	change(x,y,1);change(xx+1,y,1);
		 	change(xx+1,yy+1,1);change(x,yy+1,1);
		 }else{
		 	int x=red(),y=red();
		 	printf("%d\n",ask(x,y));
		 }
		putchar(10);
	}
	return 0;
}
