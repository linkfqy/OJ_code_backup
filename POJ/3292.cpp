#include<cstdio>
#include<cstring>
const int maxn=1000005,n=1000001;
int h,p[maxn],s[maxn];
bool vis[maxn];
void make_prime(){
	for (int i=1;(i<<2|1)<=n;i++){
		int j=i<<2|1;
		if (!vis[j]){
			p[++p[0]]=j;
			for (int k=2;k*j<=n;k++) vis[k*j]=1;
		}
	}
}
int main(){
	make_prime();
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=p[0]&&p[i]*p[i]<=n;i++)
	 for (int j=i;j<=p[0];j++){
	 	int x=p[i]*p[j];
	 	if (x>n) break;
	 	if (x%4==1&&!vis[x]) vis[x]=1;
	 }
	for (int i=1;i<=n;i++) s[i]=s[i-1]+vis[i];
	for (scanf("%d",&h);h;scanf("%d",&h))
	 printf("%d %d\n",h,s[h]);
	return 0;
}






























/*
很明显，可以直接筛法挖出H-prime，对于得到H-semi-prime，可以直接暴力刷，不会TLE 
为什么？因为我们找H-semi-prime很明显要小于10^6，所以对于很大的H-prime,找不到与他相乘的H-prime，使得乘积小于10^6 
*/
