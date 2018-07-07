#include<cstdio>
#include<cstring>
#define cl(x,y) memset(x,y,sizeof(x))

const int maxn=400005;
int n,m,sa[maxn];
char s[maxn];
int rk[maxn],t[maxn],buc[maxn];
void get_sa(){
	cl(buc,0);
	for (int i=1;i<=n;i++) buc[rk[t[i]]]++;
	for (int i=1;i<=m;i++) buc[i]+=buc[i-1];
	for (int i=n;i>=1;i--) sa[buc[rk[t[i]]]--]=t[i];
}
void make_sa(){
	m=128;
	for (int i=1;i<=n;i++) rk[i]=s[i],t[i]=i;
	get_sa();
	for (int k=1;k<n;k<<=1){
		int p=0;
		for (int i=n-k+1;i<=n;i++) t[++p]=i;
		for (int i=1;i<=n;i++) if (sa[i]>k) t[++p]=sa[i]-k;
		get_sa(); t[sa[1]]=p=1;
		for (int i=2;i<=n;i++)
		 if (rk[sa[i]]==rk[sa[i-1]]&&rk[sa[i]+k]==rk[sa[i-1]+k]) t[sa[i]]=p;else t[sa[i]]=++p;
		memcpy(rk,t,sizeof(t));
		if (p==n) break;
		m=p;
	}
}
int main(){
	scanf("%s",s+1); n=strlen(s+1);
	for (int i=1;i<=n;i++) s[n+i]=s[i];n+=n;
	make_sa();
	for (int i=1;i<=n;i++)
	 if (sa[i]<=(n>>1)) putchar(s[sa[i]+(n>>1)-1]);
	return 0;
}
