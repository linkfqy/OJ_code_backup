#include<cstdio>
typedef long long ll;

const int maxn=45;
int tst,n,q,m,a[maxn],biao[maxn][maxn];
ll S;
inline ll sum(int x,int y,int xx,int yy){
	ll res=0;
	for (int i=x;i<=xx;i++)
	 for (int j=y;j<=yy;j++) res+=biao[i][j];
	return res;
}
int main(){
	scanf("%d",&tst);
	while (tst--){
		scanf("%d",&n); m=2*n;
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		int cur=0;
		for (int i=0;i<=4*n;i++)
		 for (int j=0;j<=i;j++) biao[j][i-j]=a[cur],(++cur)%=n;
		S=0;
		for (int i=0;i<m;i++)
		 for (int j=0;j<m;j++) S+=biao[i][j];
		scanf("%d",&q);
		while (q--){
			int x,y,xx,yy;scanf("%d%d%d%d",&x,&y,&xx,&yy);
			int X=xx/m-x/m-1,Y=yy/m-y/m-1;
			ll ans=S*X*Y;
			ans+=X*sum(0,y%m,m-1,m-1);
			ans+=X*sum(0,0,m-1,yy%m);
			ans+=Y*sum(0,0,xx%m,m-1);
			ans+=Y*sum(x%m,0,m-1,m-1);
			
			ans+=sum(x%m,y%m,m-1,m-1);
			ans+=sum(0,0,xx%m,yy%m);
			ans+=sum(x%m,0,m-1,yy%m);
			ans+=sum(0,y%m,xx%m,m-1);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
