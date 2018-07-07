#include<cstdio>
#include<cstring>
const int maxn=50005;
int n,q,fa[maxn],s[maxn],ans=0;
inline int red(){
	int tot=0;char ch=getchar();
	while (ch<'0'||'9'<ch) ch=getchar();
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot;
}
int getfa(int x){
	if (fa[x]==x) return x;
	int father=fa[x];
	fa[x]=getfa(fa[x]);
	s[x]=(s[x]+s[father])%3;
	return fa[x];
}
int main(){
	n=red(),q=red();
	for (int i=1;i<=n;i++) fa[i]=i;
	while (q--){
		int ch=red(),x=red(),y=red();
		if (x>n||y>n) {ans++;continue;}
		if (ch==1){
			int fx=getfa(x),fy=getfa(y);
			if (fx!=fy) fa[fx]=fy,s[fx]=(s[y]-s[x]+3)%3;else ans+=(s[x]-s[y]+3)%3!=0;
		}else{
			int fx=getfa(x),fy=getfa(y);
			if (fx!=fy) fa[fx]=fy,s[fx]=(s[y]-s[x]+4)%3;else ans+=(s[x]-s[y]+3)%3!=1;
		}
	}
	printf("%d",ans);
	return 0;
}








/*

*/
