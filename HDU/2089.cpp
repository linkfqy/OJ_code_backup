#include<cstdio>
#include<cstring>

int l,r,f[10][15],a[10],len;
int dfs(int stp,int lst,bool lt){
	if (stp==0) return 1;
	if (lt&&f[stp][lst]>0) return f[stp][lst];
	int res=0;
	for (int i=0,it=lt?9:a[stp];i<=it;i++){
		if (i==4||lst==6&&i==2) continue;
		res+=dfs(stp-1,i,lt||i<it);
	}
	if (lt) f[stp][lst]=res;
	return res;
}
int main(){
	memset(f,255,sizeof(f));
	for (scanf("%d%d",&l,&r);l&&r;scanf("%d%d",&l,&r)){
		int L,R;len=0;l--;
		for (int x=l;x;x/=10) a[++len]=x%10;
		L=dfs(len,0,0);
		len=0;
		for (int x=r;x;x/=10) a[++len]=x%10;
		R=dfs(len,0,0);
		printf("%d\n",R-L);
	}
	return 0;
}
