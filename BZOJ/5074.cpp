#include<cstdio>
#include<cmath>
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

const int maxn=20;
int tst,n,a[maxn];
bool check(int s){
	int sum=0;
	for (int i=1;i<=n;i++)
	 sum+=ceil((double)s/a[i]);
	return sum<=s;
}
int main(){
	tst=red();
	while (tst--){
		n=red();
		if (n>10) {while (n--) red();printf("NO\n");continue;}
		for (int i=1;i<=n;i++) a[i]=red();
		bool suc=0;
		for (int i=1;i<=500000;i++)
		 if (check(i)) {suc=1;break;}
		if (suc) printf("YES\n");else printf("NO\n");
	}
	return 0;
}
