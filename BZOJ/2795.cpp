#include<cstdio>
#define ull unsigned long long

const int maxn=500005;
int n,q,p[maxn],nxt[maxn]; bool vis[maxn];
char s[maxn];
void makep(int n){
	nxt[1]=1;
	for (int i=2;i<=n;i++){
		if (!vis[i]) p[++p[0]]=i,nxt[i]=i;
		for (int j=1;j<=p[0]&&i*p[j]<=n;j++){
			vis[i*p[j]]=1;nxt[i*p[j]]=p[j];
			if (i%p[j]==0) break;
		}
	}
}
ull sum[maxn],pw[maxn];
inline ull getha(int l,int r){
	if (l>r) return 0;
	return sum[r]-sum[l-1]*pw[r-l+1];
}
int main(){
	scanf("%d%s",&n,s+1);makep(n);pw[0]=1;
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]*233+s[i],pw[i]=pw[i-1]*233;
	scanf("%d",&q);
	while (q--){
		int l,r,tem,len,mn;scanf("%d%d",&l,&r);
		for (tem=len=r-l+1,mn=nxt[tem];tem>1;mn=nxt[tem]){
			while (len%mn==0&&getha(l,r-len/mn)==getha(l+len/mn,r)) len/=mn;
			while (tem%mn==0) tem/=mn;
		}
		printf("%d\n",len);
	}
	return 0;
}
