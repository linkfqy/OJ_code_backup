#include<cstdio>
#include<cstring>

const int maxn=10005;
int n,ans;
char s[maxn];
int main(){
	scanf("%s",s);n=strlen(s);
	ans=(n-1)*10;
	for (char c='1';c<='9';c++){
		int suc=1;
		for (int i=0;i<n;i++)
		 if (s[i]>c) break;else
		 if (s[i]<c) {suc=0;break;}
		if (suc) ans++;
	}
	printf("%d",ans);
	return 0;
} 
