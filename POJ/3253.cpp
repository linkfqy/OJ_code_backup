#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
const int maxn=20005;
int n,hep[maxn],len;
LL ans;
void psh(int x){
	hep[++len]=x;int son=len;
	while (son!=1&&hep[son]<hep[son>>1]) swap(hep[son],hep[son>>1]),son>>=1;
}
int pop(){
	int res=hep[1];hep[1]=hep[len--];int fa=1,son;
	while ((fa<<1)<=len){
		if ((fa<<1|1)>len||hep[fa<<1]<hep[fa<<1|1]) son=fa<<1;else son=fa<<1|1;
		if (hep[son]<hep[fa]) swap(hep[son],hep[fa]),fa=son;else break;
	}
	return res;
}
inline int red(){
	int tot=0;char ch=getchar();
	while (ch<'0'||'9'<ch) ch=getchar();
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot;
}
int main(){
	n=red();
	for (int i=1;i<=n;i++) psh(red());
	while (len>1){
		int x=pop(),y=pop();
		ans+=x+y;psh(x+y);
	}
	printf("%lld",ans);
	return 0;
}
