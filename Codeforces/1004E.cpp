#include<cstdio> 
#include<set>
#include<algorithm>
using namespace std;

const int maxn=100005;
int n,K,f[maxn];
struct data{
	int x,w;
	data () {}
	data (int _x,int _w):x(_x),w(_w) {}
	bool operator<(const data&b)const {return w<b.w||w==b.w&&x<b.x;}
};
set<data> d[maxn],S;
int main(){
	freopen("e.in","r",stdin);
	scanf("%d%d",&n,&K);
	for (int i=1,x,y,z;i<n;i++)
	 scanf("%d%d%d",&x,&y,&z),
	 d[x].insert(data(y,z)),d[y].insert(data(x,z)),
	 f[x]++,f[y]++;
	for (int i=1;i<=n;i++)
	 if (f[i]==1) S.insert(data(i,(*d[i].begin()).w));
	int ans=0;
	while (n>K||S.size()>2){
		int x=(*S.begin()).x,fa=(*d[x].begin()).x,w=(*d[x].begin()).w;
		ans=(*S.begin()).w; S.erase(S.begin()); n--;
		f[fa]--; d[fa].erase(d[fa].find(data(x,w)));
		if (f[fa]==1) S.insert(data(fa,(*d[fa].begin()).w+ans));
	}
	printf("%d",ans);
	return 0; 
}
