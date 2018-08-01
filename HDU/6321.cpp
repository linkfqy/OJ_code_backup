#include<cstdio>
#include<cstring>
#define cl(x,y) memset(x,y,sizeof(x))
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
inline char fstchar(){
	char ch=nc();while (ch!='+'&&ch!='-') ch=nc();
	return ch;
}

const int maxs=1030,MOD=1e9+7;
int tst,n,q,f[maxs],h[maxs],num1[maxs];
int main(){
	tst=red();
	for (int s=0;s<1024;s++){
		for (int x=s;x;x>>=1) num1[s]+=x&1;
	}
	while (tst--){
		n=red(),q=red(); cl(f,0);f[0]=1;
		while (q--){
			if (fstchar()=='+'){
				int u=red(),v=red();
				for (int s=(1<<n)-1;s>=0;s--)
				 if ((s&(1<<u-1))&&(s&(1<<v-1))) (f[s]+=f[s^(1<<u-1)^(1<<v-1)])%=MOD;
			}else{
				int u=red(),v=red();
				for (int s=0;s<(1<<n);s++)
				 if ((s&(1<<u-1))&&(s&(1<<v-1))) (f[s]-=f[s^(1<<u-1)^(1<<v-1)])%=MOD;
			}
			cl(h,0);
			for (int s=0;s<(1<<n);s++)
			 (h[num1[s]]+=f[s])%=MOD;
			bool fir=1;
			for (int k=1;k<=n/2;k++)
			 printf(fir?(fir=0,"%d"):" %d",(h[k*2]+MOD)%MOD);
			putchar('\n');
		}
	}
	return 0;
}
