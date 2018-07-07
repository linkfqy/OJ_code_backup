#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;

const int maxn=50005;
int n,m,a[maxn],b[maxn];
ll ans;
char s[maxn];
priority_queue<int,vector<int>,greater<int> > Q;
int main(){
	scanf("%s",s);n=strlen(s);
	for (int i=0;i<n;i++) if (s[i]=='?') m++;
	for (int i=1;i<=m;i++) scanf("%d%d",&a[i],&b[i]);
	int S=0;
	for (int i=0,t=0;i<n;i++){
		if (s[i]=='?'){
		 t++;ans+=b[t];Q.push(a[t]-b[t]);S--;
		}else S+=(s[i]=='(')?1:-1;
		while (!Q.empty()&&S<0) S+=2,ans+=Q.top(),Q.pop();
		if (S<0) return printf("-1"),0;
	}
	if (S>0) return printf("-1"),0;
	printf("%lld",ans);
	return 0;
}
