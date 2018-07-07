#include<cstdio>
#include<cstring>
#include<cmath>
int tst,s,t,ans,f[10005];
bool vis[10005];
struct ha{
	int s[5];
	int get(){
		int res=0;
		for (int i=4;i>=1;i--) res=res*10+s[i];
		return res;
	}
	void operator=(int b){
		for (int i=1;i<=4;i++)
		 s[i]=b%10,b/=10;
	}
}que[10005];
bool is_prime(int x){
	int ti=sqrt((double)x);
	for (int i=2;i<=ti;i++)
	 if (x%i==0) return 0;
	return 1;
}
bool check(int x){
	if (vis[x]||x<1000) return 0;
	return is_prime(x);
}
bool bfs(){
	memset(vis,0,sizeof(vis));
	int hed=0,til=1;
	vis[s]=1;que[1]=s;ans=0;f[1]=0;
	if (s==t) return 1;
	while (hed!=til){
		hed++;
		for (int i=1;i<=4;i++){
			ha x=que[hed];
			for (int j=0;j<=9;j++){
				x.s[i]=j;
				if (check(x.get())){
					que[++til]=x;vis[x.get()]=1;
					f[til]=f[hed]+1;
					if (x.get()==t) {ans=f[til];return 1;}
				}
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d",&tst);
	while (tst--){
		scanf("%d%d",&s,&t);
		if (bfs()) printf("%d\n",ans);else printf("Impossible\n");
	}
	return 0;
}
