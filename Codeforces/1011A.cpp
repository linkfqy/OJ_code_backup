#include<cstdio>

int n,k,num[30];
char s[55];
int main(){
	scanf("%d%d%s",&n,&k,s);
	for (int i=0;i<n;i++) num[s[i]-'a'+1]++;
	int lst=-1,ans=0;
	while (k){
		int i;bool suc=0;
		for (i=lst+2;i<=26;i++)
		 if (num[i]) {suc=1;break;}
		if (!suc) break;
		ans+=i;lst=i;k--;
	}
	if (k) return puts("-1"),0;
	printf("%d",ans);
	return 0;
}
