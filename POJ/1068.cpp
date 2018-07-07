#include<cstdio>
const int maxn=25;
int stk[maxn],tst,q[maxn];
inline int red(){
	int tot=0;char ch=getchar();
	while (ch<'0'||'9'<ch) ch=getchar();
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot;
}
int main(){
	tst=red();
	while (tst--){
		int n=red(),tim=1;
		for (int i=1;i<=n;i++){
			int x=red();
			while (tim<=x) stk[++stk[0]]=tim++;
			q[i]=x-stk[stk[0]--]+1;
		}
		for (int i=1;i<n;i++)
		 printf("%d ",q[i]);
		printf("%d\n",q[n]);
	}
	return 0;
}
