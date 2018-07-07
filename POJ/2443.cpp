#include<cstdio>
#include<bitset>
using namespace std;
#define nc getchar
int n,q;
bitset<1002> S[10002];
inline int red(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
	return res*f;
}
int main(){
	n=red();
	for (int i=1;i<=n;i++)
	 for (int j=1,k=red();j<=k;j++)
	  S[red()].set(i);
	q=red();
	while (q--){
		int i=red(),j=red();
		if ((S[i]&S[j]).any()) printf("Yes\n");else printf("No\n");
	}
	return 0;
}
