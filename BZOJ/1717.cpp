#include<cstdio>
#include<cstring>
#define cl(x,y) memset(x,y,sizeof(x))

const int maxn=20005,maxm=1000005;
int n,m,K,sa[maxn],rk[maxn],ht[maxn],s[maxn];
int buc[maxm],t[maxn];
void get_sa(){
	cl(buc,0);
	for (int i=1;i<=n;i++) buc[rk[t[i]]]++;
	for (int i=1;i<=m;i++) buc[i]+=buc[i-1];
	for (int i=n;i>=1;i--) sa[buc[rk[t[i]]]--]=t[i];
}
void make_sa(){
	m=1e6;
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
	for (int i=1,h=0;i<=n;i++){
		if (h) h--;
		int j=sa[rk[i]-1];
		while (s[i+h]==s[j+h]) h++;
		ht[rk[i]]=h;
	}
}
bool check(int mid){
	for (int i=2,tot=1;i<=n;i++){
		if (ht[i]<mid) tot=0;
		tot++;
		if (tot>=K) return 1;
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&K);
	for (int i=1;i<=n;i++) scanf("%d",&s[i]);
	make_sa();
	int l=0,r=n,ans=0;
	while (l<=r){
		int mid=l+r>>1;
		if (check(mid)) l=mid+1,ans=mid;else r=mid-1;
	}
	printf("%d",ans);
	return 0;
}
