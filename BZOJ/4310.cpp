#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef long long ll;

const int maxn=100005;
int n,m,K,sa[maxn],rk[maxn],ht[maxn],ansl,ansr;
char s[maxn];
int t[maxn],buc[maxn],f[maxn][20],w[maxn];
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
	for (int k=1,p=0;k<n&&p<n;k<<=1,m=p){
		p=0;
		for (int i=n-k+1;i<=n;i++) t[++p]=i;
		for (int i=1;i<=n;i++) if (sa[i]>k) t[++p]=sa[i]-k;
		get_sa(); t[sa[1]]=p=1;
		for (int i=2;i<=n;i++)
		 if (rk[sa[i]]==rk[sa[i-1]]&&rk[sa[i]+k]==rk[sa[i-1]+k]) t[sa[i]]=p;else t[sa[i]]=++p;
		memcpy(rk,t,sizeof(rk));
		if (p==n) break;
		m=p;
	}
	for (int i=1,h=0;i<=n;i++){
		if (h) h--;
		int j=sa[rk[i]-1];
		while (s[i+h]==s[j+h]) h++;
		ht[rk[i]]=h;
	} ht[1]=0;
	for (int i=1;i<=n;i++) f[i][0]=ht[i];
	for (int j=1;j<=log2(n);j++)
	 for (int i=1;i+(1<<j)-1<=n;i++)
	  f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1]);
}
inline int LCP(int l,int r){
	if (l==r) return n-l+1;
	l=rk[l];r=rk[r]; if (l>r) swap(l,r); l++;
	int j=log2(r-l+1);
	return min(f[l][j],f[r-(1<<j)+1][j]);
}
inline bool cmp(int l,int r,int ll,int rr){
	int n1=r-l+1,n2=rr-ll+1,k=LCP(l,ll);
	if (n1<=n2&&k>=n1) return 1;
	if (n1>n2&&k>=n2) return 0;
	return s[l+k]<=s[ll+k];
}
bool check(ll mid){
	int l,r,num=1,lst=n;
	for (int i=1;i<=n;i++)
	 if (w[i]<mid) mid-=w[i];else {l=sa[i];r=n-w[i]+mid;;break;}
	for (int i=n;i>=1;i--){
		if (s[i]>s[l]) return 0;
		if (!cmp(i,lst,l,r)) lst=i,num++;
		if (num>K) return 0;
	}
	ansl=l;ansr=r;return 1;
}
int main(){
	scanf("%d%s",&K,s+1);n=strlen(s+1);
	make_sa();
	ll l=1,r=0;
	for (int i=1;i<=n;i++) w[i]=n-sa[i]+1-ht[i],r+=w[i];
	while (l<=r){
		ll mid=l+r>>1;
		if (check(mid)) r=mid-1;else l=mid+1;
	}
	for (int i=ansl;i<=ansr;i++) putchar(s[i]);
	return 0;
}
