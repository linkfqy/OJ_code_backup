#include<cstdio>
typedef long long ll;
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

const int maxn=100005;
const double eps=1e-5;
int n,a[maxn];
double L,R,mid,ans,s[maxn],c[maxn];
ll res,k;
void ms(int L,int R){
	if (L>=R) return;
	int mid=L+R>>1;
	ms(L,mid);ms(mid+1,R);
	int i=L,j=mid+1;
	for (int k=L;k<=R;k++) c[k]=s[k];
	for (int k=L;k<=R;k++)
	 if (i<=mid&&(j>R||c[i]<=c[j])) s[k]=c[i++];else s[k]=c[j++],res-=mid-i+1;
}
//  ƽ��ֵ����mid����������Ƿ����K
bool check(){
	s[0]=0;
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i]-mid;
	res=(ll)n*(n+1)/2;
	ms(0,n);
	return res>=k;
}
int main(){
	scanf("%d%lld",&n,&k);
	for (int i=1;i<=n;i++) a[i]=red();
	L=1,R=1e5;
	while (R-L>=eps){
		mid=(L+R)/2;
		if (check()) ans=mid,L=mid;else R=mid;
	}
	printf("%.4lf",ans);
	return 0;
}
