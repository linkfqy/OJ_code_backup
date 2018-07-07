#include<cstdio>
#include<cstring>
const int maxn=105,maxv=100005;
int allv,n,nn,w[maxn];
bool f[maxv];
int main(){
	while (scanf("%d%d",&allv,&n)==2){
		nn=0;
		for (int i=1;i<=n;i++){
			int ni,wi;scanf("%d%d",&ni,&wi);
			for (int k=1;ni>k;k<<=1)
			 w[++nn]=wi*k,ni-=k;
			w[++nn]=wi*ni;
		}
		memset(f,0,sizeof(f));
		f[0]=1;
		for (int i=1;i<=nn;i++)
		 for (int j=allv;j>=w[i];j--)
		  f[j]|=f[j-w[i]];
		for (int i=allv;i>=0;i--)
		 if (f[i]){printf("%d\n",i);break;}
	}
	return 0;
}
