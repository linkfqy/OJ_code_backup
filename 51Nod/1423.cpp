#include<cstdio>
#include<algorithm>
using namespace std;
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

const int maxn=100005;
int n,a[maxn],stk[maxn],ans=0;
int main(){
	n=red();
	for (int i=1;i<=n;i++){
		a[i]=red();
		while (stk[0]&&a[stk[stk[0]]]<a[i]) stk[0]--;
		if (stk[0]) ans=max(ans,a[stk[stk[0]]]^a[i]);
		stk[++stk[0]]=i;
	}
	stk[0]=0;
	for (int i=n;i;i--){
		while (stk[0]&&a[stk[stk[0]]]<a[i]) stk[0]--;
		if (stk[0]) ans=max(ans,a[stk[stk[0]]]^a[i]);
		stk[++stk[0]]=i;
	}
	printf("%d",ans);
	return 0;
} 
