#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,ans1,ans2;

int main(){
	scanf("%d",&n);
	for (int i=1,x;i<=n;i++) scanf("%d",&x),ans1+=x;
	for (int i=1,x;i<=n;i++) scanf("%d",&x),ans2+=x;
	return puts(ans1<ans2?"No":"Yes"),0;
}
