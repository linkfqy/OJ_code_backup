#include<cstdio>
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

int tst,n;
int main(){
	tst=red();
	while (tst--){
		n=red();int sum=0;
		for (int i=1;i<=n;i++) sum^=red();
		for (int i=1;i<n;i++) red(),red();
		puts(sum==0?"D":"Q") ;
	}
	return 0;
}
