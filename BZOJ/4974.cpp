#include<cstdio>

const int maxn=100005;
int n,nxt[maxn];
char s[maxn];
bool check(int i,char c){
	s[i]=c; int j=nxt[i-1];
	while (j&&s[j+1]!=s[i]) j=nxt[j];
	return (s[j+1]==s[i]?j+1:j)==nxt[i];
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&nxt[i]),nxt[i]=i-nxt[i];
	s[1]='a';
	for (int i=2;i<=n;i++){
		for (char c='a';c<='z';c++)
		 if (check(i,c)) break;
	}
	printf("%s",s+1);
	return 0;
}
