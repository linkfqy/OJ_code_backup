#include<cstdio>
#include<queue>
#include<algorithm>
#define LL long long
using namespace std;

const int maxn=300005;
int n;
struct data{
	LL t,w;
	data () {}
	data (LL _t,LL _w):t(_t),w(_w) {}
	bool operator<(const data&b)const{
		return t<b.t;
	}
	LL v()const {return w-t+1;}
}a;
struct cmp{	
	bool operator()(data&a,data&b){
		return a.w-a.t>b.w-b.t;
	}
};
priority_queue<data,vector<data>,cmp> A;
priority_queue<data> B;
int main(){
	scanf("%d",&n);
	scanf("%lld%lld",&a.t,&a.w);
	for (int i=2;i<=n;i++){
		LL t,w;
		scanf("%lld%lld",&t,&w);
		if (t>a.t) A.push(data(t,w));else B.push(data(t,w));
	}
	int ans=A.size()+1;
	while (!A.empty() && a.t>=A.top().v()){
		a.t-=(A.top()).v();
		A.pop();
		while (!B.empty() && B.top().t>a.t) A.push(B.top()),B.pop();
		ans=min(ans,(int)A.size()+1);
	}
	printf("%d",ans);
	return 0;
}
