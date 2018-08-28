#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

char s[300005];
int main(){
	int n,x,y;ll cnt=0;
	scanf("%d%d%d%s",&n,&x,&y,s+1);
	s[0]='1';
	for (int i=1;i<=n;i++) cnt+=(s[i-1]=='1'&&s[i]=='0');
	if (cnt==0) return puts("0"),0;
	printf("%lld",min(cnt*y,(cnt-1)*x+y));
	return 0;
}
