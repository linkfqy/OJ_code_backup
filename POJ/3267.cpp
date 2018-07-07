#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=605,maxl=305;
int n,l,f[maxl];
char s[maxl],a[maxn][30];
int main(){
	scanf("%d%d",&n,&l);
	scanf("%*[^\n]");getchar();
	for (int i=1;i<=l;i++) s[i]=getchar();
	for (int i=1;i<=n;i++) scanf("%s",a[i]);
	memset(f,63,sizeof(f));
	f[0]=0;
	for (int j=1;j<=l;j++){ f[j]=min(f[j-1]+1,f[j]);
	 for (int i=1;i<=n;i++)
	  if (s[j]==a[i][0]){
	  	int x=0,ii=0,jj=j;bool suc=1;
	  	while (a[i][ii]&&s[jj]){
	  		while (a[i][ii]!=s[jj]&&s[jj]) jj++,x++;
	  		if (!s[jj]) {suc=0;break;}
	  		ii++;jj++;
	  	}
	  	if (suc&&!a[i][ii]) f[jj-1]=min(f[jj-1],f[j-1]+x);
	  }
	}
	printf("%d",f[l]);
	return 0;
}
