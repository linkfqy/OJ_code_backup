#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

const int maxn=200005;
int n;
char s[maxn];
struct data{
	int x,y,z;
	data () {}
	data (int _x,int _y,int _z):x(_x),y(_y),z(_z) {}
	bool operator<(const data&b)const {return x<b.x||x==b.x&&y<b.y||x==b.x&&y==b.y&&z<b.z;}
};
map<data,int> M;
int main(){
	scanf("%d%s",&n,s+1);
	int ans=0;
	data t(0,0,0),tt; M[t]=0;
	for (int i=1;i<=n;i++){
		if (s[i]=='J') t.x++;else
		if (s[i]=='O') t.y++;else t.z++;
		tt=data(0,t.y-t.x,t.z-t.x);
		if (M.find(tt)==M.end()) M[tt]=i;else ans=max(ans,i-M[tt]);
	}
	printf("%d",ans);
	return 0;
}
