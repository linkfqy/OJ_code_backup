#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;
inline char nc(){
	static char buf[100000],*l=buf,*r=buf;
	return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++;
}
inline int red(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
	return res*f;
}
inline void reads(char *s){
	char c=nc();while (c<'0'||'9'<c) c=nc();
	int n=0;
	while ('0'<=c&&c<='9') s[++n]=c,c=nc();
}

const int maxn=1000005,INF=0x3f3f3f3f;
int n,q,a[maxn],b[maxn],ans;
char s[maxn];
bool vis[maxn];
void calc(int x){
	int l,r,tot=0;  //(l,r)
	vis[x]=1;
	for (l=x-1;l>=1&&a[l]>=a[x]||s[l]=='0';l--){
		if (s[l]=='0') tot++;
		if (vis[l]) return;else vis[l]=1;
	}
	for (r=x+1;r<=n&&a[r]>=a[x]||s[r]=='0';r++){
		if (s[r]=='0') tot++;
		if (vis[r]) return;else vis[r]=1;
	}
	ans=min(ans,r-l-1-tot);
}
int main(){
	n=red();
	for (int i=1;i<=n;i++) a[i]=red(),b[a[i]]=i;
	q=red();
	while (q--){
		reads(s);ans=INF;cl(vis,0);
		for (int i=n;i>=1;i--)
			if (s[b[i]]=='0') calc(b[i]);
		printf("%d\n",ans);
	}
	return 0;
}
