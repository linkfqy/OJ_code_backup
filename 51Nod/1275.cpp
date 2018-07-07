#include<cstdio>
#define LL long long
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

const int maxn=50005;
int n,k,a[maxn],qu[maxn],qd[maxn];
int main(){
	n=red(),k=red();
	int hedu=1,hedd=1,tilu=0,tild=0;
	LL ans=0;int lst=0;
	for (int i=1;i<=n;i++){
		a[i]=red();
		while (hedu<=tilu&&a[i]<=a[qu[tilu]]) tilu--;
		while (hedd<=tild&&a[i]>=a[qd[tild]]) tild--;
		qu[++tilu]=i;qd[++tild]=i;
		while (a[qd[hedd]]-a[qu[hedu]]>k)
		 if (qd[hedd]<qu[hedu]) lst=qd[hedd],hedd++;else lst=qu[hedu],hedu++;
		ans+=i-lst;
	}
	printf("%lld",ans);
	return 0;
}
