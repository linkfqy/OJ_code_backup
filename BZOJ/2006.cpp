#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn=500005;
int n,k,L,R,s[maxn],f[maxn][20];
struct data{
	int i,l,r,w;
	data () {}
	data (int _i,int _l,int _r,int _w):i(_i),l(_l),r(_r),w(_w) {}
	bool operator<(const data&b)const{
		return w<b.w;
	}
};
priority_queue<data> Q;
int RMQ(int L,int R){
	int j=log2(R-L+1);
	return s[f[L][j]]<s[f[R-(1<<j)+1][j]]?f[L][j]:f[R-(1<<j)+1][j];
}
int main(){
	scanf("%d%d%d%d",&n,&k,&L,&R);
	f[0][0]=0;
	for (int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		s[i]=s[i-1]+x;f[i][0]=i;
	}
	for (int j=1,tj=log2(n+1);j<=tj;j++)
	 for (int i=0;i+(1<<j)-1<=n;i++)
	  if (s[f[i][j-1]] < s[f[i+(1<<j-1)][j-1]]) f[i][j]=f[i][j-1];else f[i][j]=f[i+(1<<j-1)][j-1];
	for (int i=1;i<=n;i++){
		int l=i-R,r=i-L;
		if (r<0) continue;l=max(l,0);
		Q.push(data(i,l,r,s[i]-s[RMQ(l,r)]));
	}
	long long ans=0;
	while (k--){
		data x=Q.top();Q.pop();
		ans+=x.w;int t=RMQ(x.l,x.r);
		if (x.l<=t-1) Q.push(data(x.i,x.l,t-1,s[x.i]-s[RMQ(x.l,t-1)]));
		if (t+1<=x.r) Q.push(data(x.i,t+1,x.r,s[x.i]-s[RMQ(t+1,x.r)]));
	}
	printf("%lld",ans);
	return 0;
}
