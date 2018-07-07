#include<cstdio>
#include<set>
#include<cstring>
using namespace std;
const int maxl=205;
struct ha{
	char s[maxl];
	bool operator<(const ha&b)const{
		return strcmp(s,b.s)<0;
	}
}x;
int tst,n,ans;
set<ha> S;
char a[maxl],b[maxl],c[maxl];
void red(char *s,int n){
	s[n-1]=getchar();
	while (s[n-1]<'A'||'H'<s[n-1]) s[n-1]=getchar();
	for (int i=n-2;i>=0;i--) s[i]=getchar();
	s[n]=0;
}
int main(){
	scanf("%d",&tst);
	for (int t=1;t<=tst;t++){
		scanf("%d",&n);S.clear();
		red(a,n);red(b,n);red(c,2*n);
		bool suc=1;
		for (ans=1;;ans++){
			for (int i=0;i<n;i++)
			 x.s[i*2]=a[i],x.s[i*2+1]=b[i];x.s[n*2]=0;
			if (strcmp(c,x.s)==0) break;
			if (S.count(x)){suc=0;break;}else S.insert(x);
			for (int i=0;i<n;i++)
			 a[i]=x.s[i+n],b[i]=x.s[i];
		}
		if (suc) printf("%d %d\n",t,ans);else printf("%d -1\n",t);
	}
	return 0;
}
