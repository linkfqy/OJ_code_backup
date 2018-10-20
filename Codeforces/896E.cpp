#include<cstdio>
#include<cmath>
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

const int maxn=100005,maxb=320;
int n,m,q,a[maxn],fa[maxn];
inline int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int rt[maxb][maxn],cnt[maxb][maxn],mx[maxb],h[maxn],bg[maxb],ed[maxb],tag[maxb];
void blocker(){
	int S=sqrt(n);
	for (int i=1;i<=n;i++){
		if (S*m<i) bg[++m]=i;
		h[i]=m;
		if (i%S==0||i==n) ed[m]=i;
	}
}
void rebuild(int b){
	mx[b]=0;
	for (int i=bg[b];i<=ed[b];i++){
		if (!rt[b][a[i]]){
			rt[b][a[i]]=i;
			fa[i]=i;
			cnt[b][a[i]]=1;
		}else{
			fa[i]=rt[b][a[i]];
			cnt[b][a[i]]++;
		}
		mx[b]=max(mx[b],a[i]);
	}
}
int tmp[maxn];
void pushdown(int b){
	for (int i=bg[b];i<=ed[b];i++)
	 if (getfa(i)==i) rt[b][a[i]]=0,cnt[b][a[i]]=0;
	for (int i=bg[b];i<=ed[b];i++) tmp[i]=a[i];
	for (int i=bg[b];i<=ed[b];i++) a[i]=tmp[getfa(i)]-tag[b];
	tag[b]=0;
}
void ist_force(int l,int r,int x){
	for (int i=h[l];i<=h[r];i++) pushdown(i);
	for (int i=l;i<=r;i++)
	 if (a[i]>x) a[i]-=x;
	for (int i=h[l];i<=h[r];i++) rebuild(i);
}
int qry_force(int l,int r,int x){
	int res=0;
	for (int i=h[l];i<=h[r];i++) pushdown(i);
	for (int i=l;i<=r;i++) res+=(a[i]==x);
	for (int i=h[l];i<=h[r];i++) rebuild(i);
	return res;
}
void merge(int &rt1,int &rt2,int &c1,int &c2,int x){
	if (rt1)
	if (rt2) fa[rt1]=rt2,c2+=c1;
	else rt2=rt1,a[rt2]=x,c2=c1;
	rt1=c1=0;
}
void ist(int b,int x){
	if (mx[b]-tag[b]>2*x){
		for (int i=1+tag[b];i<=x+tag[b];i++) merge(rt[b][i],rt[b][i+x],cnt[b][i],cnt[b][i+x],i+x);
		tag[b]+=x;
	}else{
		for (int i=x+1+tag[b];i<=mx[b];i++) merge(rt[b][i],rt[b][i-x],cnt[b][i],cnt[b][i-x],i-x);
		while (!rt[b][mx[b]]) mx[b]--;
	}
}
int qry(int b,int x){
	return x+tag[b]<=100000?cnt[b][x+tag[b]]:0;
}
int main(){
	n=red(),q=red();
	for (int i=1;i<=n;i++) a[i]=red();
	blocker();
	for (int i=1;i<=m;i++) rebuild(i);
	while (q--){
		int c=red(),l=red(),r=red(),x=red();
		if (c==1){
			if (h[l]==h[r]) ist_force(l,r,x);else{
				ist_force(l,ed[h[l]],x);
				ist_force(bg[h[r]],r,x);
				for (int i=h[l]+1;i<h[r];i++) ist(i,x);
			}
		}else{
			int ans=0;
			if (h[l]==h[r]) ans=qry_force(l,r,x);else{
				ans+=qry_force(l,ed[h[l]],x);
				ans+=qry_force(bg[h[r]],r,x);
				for (int i=h[l]+1;i<h[r];i++) ans+=qry(i,x);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
