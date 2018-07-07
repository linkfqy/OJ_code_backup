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

int tst;
int main(){
	tst=red();
	while (tst--){
		int x=red();
		if (x%4==0){
			printf("%d\n",x/4);
		}else
		if (x%4==1){
			printf("%d\n",x<9?-1:(x-9)/4+1);
		}else
		if (x%4==2){
			printf("%d\n",x<6?-1:(x-6)/4+1);
		}else
		if (x%4==3){
			printf("%d\n",x<15?-1:(x-15)/4+2);
		}
	}
	return 0;
}
