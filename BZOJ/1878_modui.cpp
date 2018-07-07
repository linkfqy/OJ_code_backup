#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=50005,maxq=200005;
int h[maxn],n,q,a[maxn],ans[maxq];
struct data{
	int l,r,id;
	bool operator<(const data&b)const{
		if (h[l]==h[b.l]) return r<b.r;
		return l<b.l;
	}
}que[maxq];
inline int red(){
	int tot=0,f=1;char ch=getchar();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=getchar();}
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot*f;
}
void blocker(){
	int k=sqrt(n);
	for (int i=1;i<=n;i++) h[i]=(i-1)/k+1;
}
int L=0,R=0,now=0,hsh[1000005];
void move(int x,int d){
	if (d==1){
		if (hsh[a[x]]==0) now++;
		hsh[a[x]]++;
	}else{
		hsh[a[x]]--;
		if (hsh[a[x]]==0) now--;
	}
}
int main(){
	n=red();
	for (int i=1;i<=n;i++) a[i]=red();
	blocker();
	q=red();
	for (int i=1;i<=q;i++) que[i].l=red(),que[i].r=red(),que[i].id=i;
	sort(que+1,que+1+q);
	for (int i=1;i<=q;i++){
		while (L<que[i].l) move(L++,-1);
		while (L>que[i].l) move(--L,1);
		while (R<que[i].r) move(++R,1);
		while (R>que[i].r) move(R--,-1);
		ans[que[i].id]=now;
	}
	for (int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
