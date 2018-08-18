#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
typedef unsigned int uint;
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

const int maxn=1000005;
int q;
uint a[2][maxn];
set<int> S;
void ist(int x,int d){
	uint i=x/32,j=x%32;
	while (1){
		uint t=a[d][i];
		a[d][i]+=(1<<j);
		if (a[d][i]==a[d^1][i]) S.erase(i);else S.insert(i);
		if (a[d][i]>t) return;
		i++;j=0;
	}
}
bool check(int k){
	uint i=k/32,j=k%32;
	if ((a[0][i]&(1<<j)-1)!=(a[1][i]&(1<<j)-1)) return (a[0][i]&(1<<j)-1)<(a[1][i]&(1<<j)-1);
	set<int>::iterator it=S.lower_bound(i);
	if (it==S.begin()) return 1; it--;
	return a[0][*it]<a[1][*it];
}
int main(){
	q=red();red(),red(),red();
	while (q--)
	 if (red()==1){
	 	int x=red(),k=red(),d=(x>0?1:(x=-x,0));
	 	for (int i=0;i<=30;i++)
	 	 if (x&(1<<i)) ist(i+k,d);
	 }else{
	 	int k=red(); uint i=k/32,j=k%32;
	 	if (check(k)) putchar((((a[0][i]>>j)^(a[1][i]>>j))&1)+48);
	 	 else putchar((((a[0][i]>>j)^(a[1][i]>>j)^1)&1)+48);
	 	putchar('\n');
	 }
	return 0;
}
