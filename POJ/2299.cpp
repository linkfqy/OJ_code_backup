#include<cstdio>
#define LL long long
const int maxn=500005;
int n;
LL a[maxn],c[maxn],ans;
inline LL red(){
	LL tot=0;char ch=getchar();
	while (ch<'0'||'9'<ch) ch=getchar();
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot;
}
void msort(int L,int R){
	if (L>=R) return;
	int mid=L+R>>1;
	msort(L,mid);msort(mid+1,R);
	for (int i=L;i<=R;i++) c[i]=a[i];
	int i=L,j=mid+1;
	for (int k=L;k<=R;k++)
	 if (j>R||i<=mid&&c[i]<=c[j]) a[k]=c[i++];
	  else a[k]=c[j++],ans+=mid-i+1;
}
int main(){
	n=red();
	while (n){
		ans=0;
		for (int i=1;i<=n;i++)
		 a[i]=red();
		msort(1,n);
		printf("%lld\n",ans);
		n=red();
	}
	return 0;
}
