#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
const int maxn=500005;
int n,m;
LL s[maxn],f[maxn];
#define nc getchar
inline int red(){
	int tot=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=nc();
	return tot*f;
}
struct point{
	LL x,y;
	point() {}
	point(LL a,LL b):x(a),y(b) {}
	point operator-(const point&b) {return point(x-b.x,y-b.y);}
}stk[maxn];
typedef point vec;
LL cross(vec a,vec b){
	return a.x*b.y-b.x*a.y;
}
LL getb(point a,LL k){
	return -a.x*k+a.y;
}
int main(){
	while (scanf("%d%d",&n,&m)==2){
		for (int i=1;i<=n;i++) s[i]=s[i-1]+red();
		memset(f,63,sizeof(f));
		f[0]=0;
		int len=1,now=1;stk[1]=point(0,0);
		for (int i=1;i<=n;i++){
			LL k=2*s[i];
			while (now<len&&getb(stk[now+1],k)<getb(stk[now],k)) now++;
			f[i]=getb(stk[now],k)+m+s[i]*s[i];
			point a(s[i],f[i]+s[i]*s[i]);
			while (len>1&&cross(stk[len]-stk[len-1],a-stk[len-1])<=0){
				len--;if (now>len) now--;
			}
			stk[++len]=a;
		}
		printf("%lld\n",f[n]);
	}
	return 0;
}
