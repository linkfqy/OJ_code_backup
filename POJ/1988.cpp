#include<cstdio>
const int maxn=30005;
int n=30000,q,fa[maxn],s[maxn],num[maxn];
inline char fstchar(){
	char ch=getchar();
	while (ch!='C'&&ch!='M') ch=getchar();
	return ch;
}
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
	s[x]+=s[father];
	return fa[x];
}
int main(){
	for (int i=1;i<=n;i++) fa[i]=i,num[i]=1;
	q=red();
	while (q--){
		char ch=fstchar();
		if (ch=='M'){
			int x=red(),y=red(),fx=getfa(x),fy=getfa(y);
			s[fx]=num[fy];num[fy]+=num[fx];
			fa[fx]=fy;getfa(fx);
		}else{
			int x=red();getfa(x);
			printf("%d\n",s[x]);
		}
	}
	return 0;
}
