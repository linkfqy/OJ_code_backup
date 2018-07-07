#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=10005,maxs=1000005;
int n,q,h[maxn],a[maxn],b[maxn],hsh[maxs],topQ,topC,ans[maxn];
struct ask{
	int l,r,ti,id;
	bool operator<(const ask&b)const{
		if (h[l]==h[b.l]){
			if (h[r]==h[b.r]) return ti<b.ti;
			return r<b.r;
		}
		return l<b.l;
	}
}que[maxn];
struct cha{
	int bf,af,i;
}Ch[maxn];
inline int red(){
	int tot=0,f=1;char ch=getchar();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=getchar();}
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot*f;
}
inline char fstchar(){
	char ch=getchar();
	while (ch<'A'||'Z'<ch) ch=getchar();
	return ch;
}
void blocker(){
	int k=pow(n,2.0/3);
	for (int i=1;i<=n;i++) h[i]=(i-1)/k+1;
}
int now=0;
void update(int x,int d){
	if (d==1){
		if (hsh[a[x]]==0) now++;
		hsh[a[x]]++;
	}else{
		if (hsh[a[x]]==1) now--;
		hsh[a[x]]--;
	}
}
void change(int x,int w,int l,int r){
	if (l<=x&&x<=r) update(x,-1),a[x]=w,update(x,1);
	 else a[x]=w;
}
int main(){
	n=red(),q=red();
	blocker();
	for (int i=1;i<=n;i++) a[i]=b[i]=red();
	for (int i=1;i<=q;i++)
	 if (fstchar()=='Q'){
	 	que[++topQ].l=red(),que[topQ].r=red();
	 	que[topQ].id=topQ;que[topQ].ti=topC;
	 }else{
	 	int x=red(),y=red();
	 	Ch[++topC].bf=b[x];Ch[topC].af=y;
	 	b[x]=y;Ch[topC].i=x;
	 }
	sort(que+1,que+1+topQ);
	update(1,1);change(Ch[1].i,Ch[1].af,1,1);
	for (int i=1,L=1,R=1,t=1;i<=topQ;i++){
		while (t<que[i].ti) t++,change(Ch[t].i,Ch[t].af,L,R);
		while (t>que[i].ti) change(Ch[t].i,Ch[t].bf,L,R),t--;
		while (L<que[i].l) update(L++,-1);
		while (L>que[i].l) update(--L,1);
		while (R<que[i].r) update(++R,1);
		while (R>que[i].r) update(R--,-1);
		ans[que[i].id]=now;
	}
	for (int i=1;i<=topQ;i++) printf("%d\n",ans[i]);
	return 0;
}
