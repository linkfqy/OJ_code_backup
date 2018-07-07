#include<cstdio>
#include<vector>
#include<algorithm>
#define pb push_back
#define lowbit(x) ((x)&-(x))
using namespace std;
inline char nc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int red(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
	return res*f;
}
inline char fstchar(){
	char ch=nc();while (ch<'A'||'Z'<ch) ch=nc();
	return ch;
}

const int maxn=200005;
int q,num,BIT[maxn],dl[maxn],dr[maxn],len;
vector<int> a[maxn];
bool vis[maxn];
void ist(int x,int w){
	for (int i=x;i<=100000;i+=lowbit(i)) BIT[i]+=w;
}
int qry(int x){
	int res=0;
	for (int i=x;i;i-=lowbit(i)) res+=BIT[i];
	return res;
}
int find(int x){
	int q=qry(x),l=1,r=x;
	if (!q) return 0;
	while (l<=r){
		int mid=l+r>>1;
		if (qry(mid)<q) l=mid+1;else r=mid-1;
	}
	return l;
}
int work(int l,int r){
	int res=0;
	for (int j=r;;){
		int t=find(j);
		if (!a[t].size()) break;
		while (a[t].size()>0){
			int id=*a[t].rbegin();
			if (dr[id]<l) return res;
			ist(dl[id],-1);
			a[t].pop_back();res++;
		}
	}
	return res;
}
int main(){
	q=red();
	while (q--)
	 if (fstchar()=='A'){
	 	int l=red(),r=red();
		int res=work(l,r);
	 	num-=res;num++;
		dl[++len]=l;dr[len]=r;
		ist(l,1);a[l].pb(len);
		printf("%d\n",res);
	 }else printf("%d\n",num);
	return 0;
}
