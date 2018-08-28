#include<cstdio>
typedef unsigned long long ull;

const int maxn=2000005;
int n,N; ull hsh[maxn],pw[maxn];
char s[maxn];
inline ull geth(int l,int r){
	return hsh[r]-hsh[l-1]*pw[r-l+1];
}
int main(){
	scanf("%d%s",&N,s+1);
	if (N%2==0) return puts("NOT POSSIBLE"),0;
	n=N>>1;pw[0]=1;
	for (int i=1;i<=N;i++) hsh[i]=hsh[i-1]*31+s[i]-'A'+1,pw[i]=pw[i-1]*31;
	int cnt=0,ans=0; ull ss=0;
	for (int i=1;i<=N;i++){
		ull L,R;
		if (i==n+1) L=geth(1,i-1),R=geth(i+1,N);else
		if (i<n+1) L=geth(1,i-1)*pw[n+1-i]+geth(i+1,n+1),R=geth(n+2,N);else
		if (i>n+1) L=geth(1,n),R=geth(n+1,i-1)*pw[N-i]+geth(i+1,N);
		if (L==R) if (ss!=L) cnt++,ans=i,ss=L;
	}
	if (!cnt) return puts("NOT POSSIBLE"),0;
	if (cnt>1) return puts("NOT UNIQUE"),0;
	for (int i=1,c=0;i<=N&&c<n;i++){
		if (ans!=i) putchar(s[i]),c++;
	}
	return 0;
}
