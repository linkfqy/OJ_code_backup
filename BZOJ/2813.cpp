#include<cstdio>
#define LL long long
const int maxn=10000005,tt=1000000007;
int q,now,A,B,C,sumg,sumf;
int e[maxn],d[maxn],g[maxn],f[maxn],p[maxn];
bool vis[maxn];
LL sqr(int x) {return (LL)x*x;}
int main(){
	scanf("%d%d%d%d%d",&q,&now,&A,&B,&C);
	d[1]=g[1]=f[1]=1;
	for (int i=2;i<=C;i++){
		if (!vis[i])
		 p[++p[0]]=i,
		 e[i]=d[i]=1,g[i]=2,
		 f[i]=(sqr(i)+1)%tt;
		for (int j=1,k;j<=p[0]&&(k=i*p[j])<=C;j++){
			vis[k]=1;
			if (i%p[j]>0)
			 e[k]=1,d[k]=i,
			 g[k]=(g[i]+g[i])%tt,
			 f[k]=(sqr(p[j])+1)*f[i]%tt;
			else{
				e[k]=e[i]+1,d[k]=d[i],
				g[k]=(LL)g[i]/(e[i]+1)*(e[k]+1)%tt,
				f[k]=(f[i]*sqr(p[j])+f[d[i]])%tt;
				break;
			}
		}
	}
	sumg=sumf=0;
	while (q--){
		(sumg+=g[now]+(now&1))%=tt;
		(sumf+=f[now]+4*(now&1))%=tt;
		now=((LL)now*A+B)%C+1;
	}
	printf("%d\n%d",sumg,sumf);
	return 0;
}
