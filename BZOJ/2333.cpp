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
inline void reads(char *s){
	char ch=nc();
	while (ch<'A'||'Z'<ch) ch=nc();
	int t=0;
	while ('0'<=ch&&ch<='9'||'A'<=ch&&ch<='Z') s[t++]=ch,ch=nc();
	s[t]=0;
}
inline int Rand() {static int x=31253125;x+=(x<<4)+1;return x;}

const int maxn=300005;
int n,q,fa[maxn],rt[maxn];
int ls[maxn],rs[maxn],key[maxn],ad[maxn],f[maxn];
inline int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
inline void addad(int x,int w) {if (x) key[x]+=w,ad[x]+=w;}
inline void pushdown(int x){
	if (ad[x]) addad(ls[x],ad[x]),addad(rs[x],ad[x]),ad[x]=0;
}
int merge(int a,int b){
	if (!a||!b) return a+b;
	if (key[a]<key[b]) swap(a,b);
	pushdown(a);
	if (Rand()&1) ls[a]=merge(ls[a],b);else rs[a]=merge(rs[a],b);
	if (ls[a]) f[ls[a]]=a; if (rs[a]) f[rs[a]]=a;
	f[a]=0;
	return a;
}
int stk[maxn];
inline void pushtag(int x){
	stk[stk[0]=1]=x;
	for (int i=x;f[i];i=f[i]) stk[++stk[0]]=f[i];
	while (stk[0]) pushdown(stk[stk[0]--]);
}
multiset<int> S;
inline void erase(int x) {S.erase(S.find(x));}
int main(){
	n=red();
	key[0]=0xc0c0c0c0;
	for (int i=1;i<=n;i++) key[i]=red(),fa[i]=rt[i]=i,S.insert(key[i]);
	q=red();
	char s[5];int AD=0;
	while (q--){
		reads(s);
		if (s[0]=='U'){
			int x=red(),y=red(),fx=getfa(x),fy=getfa(y);
			if (fx==fy) continue;
			erase(key[rt[fx]]);erase(key[rt[fy]]);
			rt[fy]=merge(rt[fy],rt[fx]); fa[fx]=fy;
			S.insert(key[rt[fy]]);
		}else
		if (s[0]=='A'){
			if (s[1]=='1'){
				int x=red(),w=red();
				pushtag(x); erase(key[rt[getfa(x)]]);
				if (ls[f[x]]==x) ls[f[x]]=0;else rs[f[x]]=0;
				int fx=getfa(x);
				if (f[x]) rt[fx]=merge(rt[fx],merge(ls[x],rs[x]));
				else rt[fx]=merge(ls[x],rs[x]);
				f[x]=ls[x]=rs[x]=0; key[x]+=w;
				rt[fx]=merge(rt[fx],x);
				S.insert(key[rt[fx]]);
			}else
			if (s[1]=='2'){
				int x=red(),w=red();
				int fx=getfa(x);
				erase(key[rt[fx]]);
				addad(rt[fx],w);
				S.insert(key[rt[fx]]);
			}else AD+=red();
		}else{
			if (s[1]=='1'){
				int x=red(); pushtag(x);
				printf("%d\n",AD+key[x]);
			}else
			if (s[1]=='2'){
				int x=red(),fx=getfa(x);
				printf("%d\n",AD+key[rt[fx]]);
			}else printf("%d\n",*(--S.end())+AD);
		}
	}
	return 0;
}
