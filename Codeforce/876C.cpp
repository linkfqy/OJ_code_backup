#include<cstdio>
#include<algorithm>
using namespace std;

int n,ans[100];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=81;i++){
		int x=n-i,tot=0;
		while (x) tot+=x%10,x/=10;
		if (tot==i) ans[++ans[0]]=n-i;
	}
	sort(ans+1,ans+1+ans[0]);
	printf("%d\n",ans[0]);
	for (int i=1;i<=ans[0];i++) printf("%d\n",ans[i]);
	return 0;
}