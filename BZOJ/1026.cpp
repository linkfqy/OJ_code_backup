#include<cstdio>
#include<cstring>
#define _abs(x) ((x)<0?-(x):(x))
#define cl(x,y) memset(x,y,sizeof(x))

const int maxn=15;
int l,r,f[maxn][maxn];
int a[maxn],len;
int dfs(int stp,int lst,bool ls,bool fir){
	if (stp==0) return 1;
	if (ls&&!fir&&f[stp][lst]!=-1) return f[stp][lst];
	int now=ls?9:a[stp],res=0;
	for (int i=0;i<=now;i++)
	 if (fir||_abs(i-lst)>=2) res+=dfs(stp-1,i,ls||i<a[stp],fir&&!i);
	return !ls||fir?res:f[stp][lst]=res;
}
int calc(int x){
	len=0;
	for (;x;x/=10) a[++len]=x%10;
	return dfs(len,0,0,1);
}
int main(){
	scanf("%d%d",&l,&r);
	cl(f,-1);
	printf("%d",calc(r)-calc(l-1));
	return 0;
}
