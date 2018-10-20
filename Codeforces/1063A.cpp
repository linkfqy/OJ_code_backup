#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100005;
int n;char s[maxn];
int main(){
	scanf("%d%s",&n,s+1);
	sort(s+1,s+n+1);
	puts(s+1);
	return 0;
}
