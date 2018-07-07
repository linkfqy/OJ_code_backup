#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=44730;
int S,p[maxn],num[maxn];
bool vis[maxn];
void make_prime(){
	int n=44725;
	for (int i=2;i<=n;i++){
		if (!vis[i]) p[++p[0]]=i;
		for (int j=1;j<=p[0]&&i*p[j]<=n;j++){
			vis[i*p[j]]=1;
			if (i%p[j]==0) break;
		}
	}
	p[0]=0;
}
bool isprime(int x){
	for (int i=1;p[i]*p[i]<=x;i++)
	 if (x%p[i]==0) return 0;
	return 1;
}
void dfs(int lst,int n,int S){
	if (S==1) {num[++num[0]]=n;return;}
	if ((S-1)>p[lst]&&isprime(S-1)) num[++num[0]]=n*(S-1);
	for (int i=lst+1;p[i]*p[i]<=S;i++)
	 for (int tot=p[i]+1,w=p[i];tot<=S;w*=p[i],tot+=w)
	  if (S%tot==0) dfs(i,n*w,S/tot);
}
int main(){
	make_prime();
	while (~scanf("%d",&S)){
		num[0]=0;dfs(0,1,S);
		printf("%d\n",num[0]);
		if (!num[0]) continue;
		sort(num+1,num+num[0]+1);
		for (int i=1;i<num[0];i++) printf("%d ",num[i]);
		printf("%d\n",num[num[0]]);
	}
	return 0;
}
