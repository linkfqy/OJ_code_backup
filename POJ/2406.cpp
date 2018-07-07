#include<cstdio>
#include<cstring>
inline char nc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int red(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
	return res*f; 
}

const int maxn=1000005;
int n,nxt[maxn];
char s[maxn];
int main(){
	scanf("%s",s+1);
	while (s[1]!='.'||s[2]){
		int n=strlen(s+1);
		nxt[1]=0;
		for (int i=2,j=0;i<=n;i++){
			while (j>0&&s[j+1]!=s[i]) j=nxt[j];
			if (s[j+1]==s[i]) j++;
			nxt[i]=j;
		}
		int ans=n-nxt[n];
		printf("%d\n",n%ans==0?n/ans:1);
		scanf("%s",s+1);
	}
	return 0;
}
