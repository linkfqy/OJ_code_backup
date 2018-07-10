#include<cstdio>
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
int n,k,m,a[maxn],hsh[maxn];
int main(){
	n=red(),k=red(),m=red();
	for (int i=1;i<=n;i++) a[i]=red(),hsh[a[i]%m]++;
	int suc=0,t,tot=0;
	for (int i=0;i<m;i++)
	 if (hsh[i]>=k) {suc=1;t=i;break;}
	if (!suc) return printf("No"),0;else printf("Yes\n");
	for (int i=1;i<=n;i++) if (a[i]%m==t&&tot<k) tot++,printf("%d ",a[i]);
	return 0;
}