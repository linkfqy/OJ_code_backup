#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;

const int maxn=200005;
int n,m,d,a[maxn],when[maxn];
struct data{
	int x,id;
	data () {}
	data (int _x,int _id):x(_x),id(_id) {}
	bool operator<(const data&b)const {return x<b.x;}
};
multiset<data> S;
typedef multiset<data>::iterator iter;
int main(){
	scanf("%d%d%d",&n,&m,&d);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),S.insert(data(a[i],i));
	int ans=0;
	while (S.size()){
		int nxt=1;ans++;
		while (1){
			iter it=S.lower_bound(data(nxt,0));
			if (it==S.end()) break;;
			when[(*it).id]=ans;
			nxt=(*it).x+d+1;S.erase(it);
		}
	}
	printf("%d\n",ans);
	for (int i=1;i<=n;i++) printf("%d ",when[i]);
	return 0;
}
