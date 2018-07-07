#include<cstdio>
#include<algorithm>
#define LL long long
#define w(x) ((i-x.t-1)*q)
using namespace std;
const int maxn=100005,maxs=7100005;
int n,m,q,t;
LL u,v;
struct data{
	int s,t;
	bool operator<(const data&b)const{
		return s>b.s;
	}
}que[maxn],Q[2][maxs],ans[maxs];
inline int red(){
	int tot=0,f=1;char ch=getchar();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=getchar();}
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot*f;
}
int main(){
	n=red(),m=red(),q=red(),u=red(),v=red(),t=red();
	for (int i=1,x;i<=n;i++) x=red(),que[i]=(data){x,0};
	sort(que+1,que+1+n);
	int hed=1,H[2]={1,1},T[2]={0,0};bool fst=1;
	for (int i=1;i<=m;i++){
		int Max=0,k;
		for (int j=0;j<2;j++)
		 if (H[j]<=T[j]&&Max<=Q[j][H[j]].s+w(Q[j][H[j]])) Max=Q[j][H[j]].s+w(Q[j][H[j]]),k=j;
		int x,y;
		if (hed<=n&&Max<=que[hed].s+w(que[hed]))
		 Max=que[hed].s+w(que[hed]),hed++;else H[k]++;
		x=Max*u/v,y=Max-x;
		Q[0][++T[0]]=(data){x,i};
		Q[1][++T[1]]=(data){y,i};
		if (i%t==0)
		 if (fst) fst=0,printf("%d",Max);else printf(" %d",Max);
	}
	fst=1;
	for (int i=m+1,tot=1;;tot++){
		int Max=-1,k;
		for (int j=0;j<2;j++)
		 if (H[j]<=T[j]&&Max<=Q[j][H[j]].s+w(Q[j][H[j]])) Max=Q[j][H[j]].s+w(Q[j][H[j]]),k=j;
		if (hed<=n&&Max<=que[hed].s+w(que[hed]))
		 Max=que[hed].s+w(que[hed]),hed++;else H[k]++;
		if (Max==-1) break;
		if (tot%t==0)
		 if (fst) fst=0,printf("\n%d",Max);else printf(" %d",Max);
	}
	return 0;
}
