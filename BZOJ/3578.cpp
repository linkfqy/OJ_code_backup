#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

const int maxn=100005;
int N,n,q,w[maxn],a[maxn],where[maxn],num[maxn];
#define brand() ((rand()<<16)|(rand()<<1)|(rand()&1))
map<int,bool> usd;
set<int> S;
char s[20];
int main(){
	srand(998244353);
	scanf("%d%d%d",&N,&n,&q);
	for (int i=1;i<=N;i++) w[i]=brand(),a[where[i]=1]^=w[i];
	S.insert(1);num[1]=N;
	while (q--){
		scanf("%s",s);
		if (s[0]=='C'){
			int x,y;scanf("%d%d",&x,&y);
			S.erase(where[x]);S.erase(y);
			a[where[x]]^=w[x]; a[y]^=w[x];
			if (!usd[a[where[x]]]) S.insert(where[x]);
			if (!usd[a[y]]) S.insert(y);
			num[where[x]]--;num[y]++;  where[x]=y;
		}else{
			int l,r;scanf("%d%d",&l,&r);
			set<int>::iterator it=S.lower_bound(l);
			int res=0;
			while (it!=S.end()&&(*it)<=r){
				res+=num[*it];
				usd[a[*it]]=1;
				S.erase(it);
				it=S.lower_bound(l);
			}
			printf("%d\n",res);
		}
	}
	return 0;
}
