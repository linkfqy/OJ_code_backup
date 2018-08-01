#include<cstdio>
typedef long long ll;
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

const int maxn=10000005;
int tst,n,m,k,p,q,r,MOD,que[maxn];
ll A,B,a[maxn];
int main(){
	tst=red();
	while (tst--){
		n=red(),m=red(),k=red(),p=red(),q=red(),r=red(),MOD=red();A=B=0;
		for (int i=1;i<=k;i++) a[i]=red();
		for (int i=k+1;i<=n;i++) a[i]=(p*a[i-1]+(ll)q*i+r)%MOD;
		int hed=1,til=0;
		for (int l=n;l>=n-m+2;l--){
			while (hed<=til&&a[que[til]]<=a[l]) til--;
			que[++til]=l;
		}
		for (int l=n-m+1;l>=1;l--){int r=l+m-1;
			while (hed<=til&&que[hed]>r) hed++;
			while (hed<=til&&a[que[til]]<=a[l]) til--;
			que[++til]=l;
			A+=a[que[hed]]^l; B+=(til-hed+1)^l;
		}
		printf("%lld %lld\n",A,B);
	}
	return 0;
}
