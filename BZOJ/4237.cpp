#include<cstdio>
#include<algorithm>
#define mp(x,y) make_pair(x,y)
#define Fst first
#define Sec second
using namespace std;
typedef long long LL;
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

const int maxn=200005,INF=0x3f3f3f3f;
int n,stk1[maxn],stk2[maxn],len1,len2,te[maxn];
LL ans;
pair<int,int> a[maxn];
bool cmpx(pair<int,int> a,pair<int,int> b){
	return a.Fst<b.Fst;
}
bool cmpy(pair<int,int> a,pair<int,int> b){
	return a.Sec<b.Sec;
}
int find(int x){
	return upper_bound(te+1,te+1+len2,x)-te;
}
void divide(int L,int R){
	if (L==R) return;
	int mid=L+R>>1;
	divide(L,mid);divide(mid+1,R);
	sort(a+L,a+mid+1,cmpx);sort(a+mid+1,a+R+1,cmpx);
	len1=len2=stk1[0]=stk2[0]=0;
	for (int i=mid+1,j=L-1;i<=R;i++){
		while (len1&&a[stk1[len1]].Sec>a[i].Sec) len1--;
		stk1[++len1]=i;
		while (j<mid&&a[j+1].Fst<a[i].Fst){
			j++;
			while (len2&&a[stk2[len2]].Sec<a[j].Sec) len2--;
			stk2[++len2]=j;te[len2]=a[j].Fst;
		}
		ans+=len2-find(a[stk1[len1-1]].Fst)+1;
	}
}
int main(){
	n=red();a[0]=mp(-INF,-INF);
	for (int i=1,x,y;i<=n;i++)
	 x=red(),y=red(),a[i]=mp(x,y);
	sort(a+1,a+1+n,cmpy);
	divide(1,n);
	printf("%lld",ans);
	return 0;
}
