#include<cstdio>
#include<cstring>

const int maxn=400005;
int n,nxt[maxn],stk[maxn];
char s[maxn];
int main(){
	while (~scanf("%s",s+1)){
		n=strlen(s+1);
		for (int i=2,j=0;i<=n;i++){
			while (j>0&&s[j+1]!=s[i]) j=nxt[j];
			if (s[j+1]==s[i]) j++;
			nxt[i]=j;
		}
		stk[0]=0;
		for (int j=n;j;j=nxt[j]) stk[++stk[0]]=j;
		for (int i=stk[0];i;i--) printf("%d ",stk[i]);printf("\n");
	}
	return 0;
}
