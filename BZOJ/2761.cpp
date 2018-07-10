#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
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

const int maxn=50005;
int tst,n;
set<int> S;
int main(){
	tst=red();
	while (tst--){
		n=red();S.clear();
		for (int i=1;i<=n;i++){
			int x=red();
			if (S.count(x)==0) printf("%d ",x),S.insert(x);
		}putchar('\n');
	}
	return 0;
}
