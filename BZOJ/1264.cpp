#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=100005;
int n,N,a[maxn],b[maxn];
vector<int> pos[maxn];
int BIT[maxn];
#define lowbit(x) ((x)&-(x))
void ist(int x,int w){
	for (int i=x;i<=N;i+=lowbit(i))
	 BIT[i]=max(BIT[i],w);
}
int qry(int x){
	int res=0;
	for (int i=x;i;i-=lowbit(i))
	 res=max(res,BIT[i]);
	return res;
}
int main(){
	scanf("%d",&n);N=n*5;
	for (int i=1;i<=N;i++) scanf("%d",&a[i]);
	for (int i=1;i<=N;i++) scanf("%d",&b[i]),pos[b[i]].push_back(i);
	for (int i=1;i<=N;i++)
	 for (int j=4;j>=0;j--)
	  ist(pos[a[i]][j],qry(pos[a[i]][j]-1)+1);
	printf("%d",qry(N));
	return 0;
}
