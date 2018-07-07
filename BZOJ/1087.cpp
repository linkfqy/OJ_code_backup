#include<cstdio>
#include<cstring>
#define LL long long
const int maxs=1030,maxk=105;
int n,K;
LL f[2][maxs][maxk],ans=0;
bool check(int i,int j,int s){
	if (i>1&&j>1&&(s&(1<<n))) return 0;
	if (i>1&&(s&(1<<n-1))) return 0;
	if (i>1&&j<n&&(s&(1<<n-2))) return 0;
	if (j>1&&(s&1)) return 0;
	return 1;
}
int main(){
	scanf("%d%d",&n,&K);
	int c=0;f[0][0][0]=1;
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=n;j++){
	 	c^=1;memset(f[c],0,sizeof(f[c]));
	 	for (int s=0;s<(1<<n+1);s++){
	 		int ss=(s<<1)%(1<<n+1);
	 		for (int k=0;k<=K;k++){
	 			f[c][ss][k]+=f[c^1][s][k];
	 			if (k<K&&check(i,j,s)) f[c][ss+1][k+1]+=f[c^1][s][k];
	 		}
	 	}
	 }
	for (int s=0;s<(1<<n+1);s++) ans+=f[c][s][K];
	printf("%lld",ans);
	return 0;
}
