#include<cstdio>
#include<cstring>

const int maxn=100005;
int n,m,l[maxn],r[maxn],ans1,ans2,len;
char a[maxn],b[maxn];
int main(){
	scanf("%s%s",a+1,b+1);n=strlen(a+1),m=strlen(b+1);len=m;
	for (int i=1,j=1;i<=m;i++){
		while (j<=n&&a[j]!=b[i]) l[j++]=i-1;
		if (j>n) break;l[j++]=i;
	}
	for (int i=m,j=n;i;i--){
		while (j&&a[j]!=b[i]) r[j--]=i+1;
		if (!j) break;r[j--]=i;
	}
	l[0]=0;r[n+1]=m+1;
	for (int i=0;i<=n;i++){
		if (r[i+1]-l[i]-1<len) len=r[i+1]-l[i]-1,ans1=l[i],ans2=r[i+1];
	}
	if (len==m) return printf("-"),0;
	if (len<=0){
		for (int i=1;i<=m;i++) putchar(b[i]);
		return 0;
	}
	for (int i=1;i<=ans1;i++) putchar(b[i]);
	for (int i=ans2;i<=m;i++) putchar(b[i]);
	return 0;
}
