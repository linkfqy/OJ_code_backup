#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;

const int maxn=100005,maxe=100005;
const ull MOD=499999999999993L;
int n,q,ans[maxn]; char s[maxn]; ull w[maxn];
int tot,lnk[maxn],son[maxe],nxt[maxe];
inline void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
struct data{
	int dep,id;
	data () {}
	data (int _x,int _y):dep(_x),id(_y) {}
};
vector<data> V[maxn];
int dep[maxn],wt[maxn],H_son[maxn];
void getH(int x){
	wt[x]=1;H_son[x]=0;
	for (int j=lnk[x];j;j=nxt[j]){
		dep[son[j]]=dep[x]+1; getH(son[j]); wt[x]+=wt[son[j]];
		if (!H_son[x]||wt[H_son[x]]<wt[son[j]]) H_son[x]=son[j];
	}
}
map<ull,int> cnt[maxn];
int num[maxn*2];
bool xH[maxn];
void change(int x,int W){
	if (cnt[dep[x]][w[x]]==0) num[dep[x]]++;
	cnt[dep[x]][w[x]]+=W;
	if (cnt[dep[x]][w[x]]==0) num[dep[x]]--;
	for (int j=lnk[x];j;j=nxt[j])
	 if (!xH[son[j]]) change(son[j],W);
}
void dsu(int x,bool keep){
	for (int j=lnk[x];j;j=nxt[j])
	 if (son[j]!=H_son[x]) dsu(son[j],0);
	if (H_son[x]) dsu(H_son[x],1),xH[H_son[x]]=1;
	change(x,1); xH[H_son[x]]=0;
	for (int i=0;i<V[x].size();i++){
		ans[V[x][i].id]=num[V[x][i].dep+dep[x]];
	}
	if (!keep) change(x,-1);
}
int main(){
	scanf("%d",&n);
	for (int i=1,fa;i<=n;i++){
		scanf("%s%d",s,&fa); add(fa,i);
		for (int j=0;s[j];j++) w[i]=(w[i]*233+s[j])%MOD;
	}
	scanf("%d",&q);
	for (int i=1;i<=q;i++){
		int x,y;scanf("%d%d",&x,&y);
		V[x].push_back(data(y,i));
	}
	getH(0);dsu(0,0);
	for (int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
