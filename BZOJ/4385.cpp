#include<cstdio>
#include<algorithm>
using namespace std;
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

const int maxn=2000005;
int n,l,a[maxn],que[maxn];
ll s[maxn],g[maxn],S;
int main(){
	scanf("%d%lld%d",&n,&S,&l);
	for (int i=1;i<=n;i++) a[i]=red(),s[i]=s[i-1]+a[i],g[i]=s[i]-s[max(i-l,0)];
	int ans=l,hed=1,til=0;
	for (int i=1,j=1;i<=n;i++){
		while (hed<=til&&g[que[til]]<=g[i]) til--;
		que[++til]=i;
		while (s[i]-s[j-1]-g[que[hed]]>S){
			j++;if (hed<=til&&que[hed]-l<j-1) hed++;
		}
		ans=max(ans,i-j+1);
	}
	printf("%d",ans);
	return 0;
}
