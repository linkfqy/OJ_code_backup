#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=500005,maxe=250005;
int ans,num,n,e,f[maxn],fa[maxn],hsh[maxn];
struct data{
	char s[11];
	bool operator<(const data&b)const{
		return strcmp(s,b.s)<0;
	}
}a[maxn],u[maxe],v[maxe];
int getfa(int x){
	if (fa[x]==x) return x;
	return fa[x]=getfa(fa[x]);
}
void marge(int x,int y){
	fa[getfa(x)]=getfa(y);
}
int main(){
	for (data x,y;scanf("%s%s",x.s,y.s)==2;){
		a[++n]=x;fa[n]=n;a[++n]=y;fa[n]=n;
		u[++e]=x;v[e]=y;
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=e;i++){
		int x=lower_bound(a+1,a+1+n,u[i])-a,y=lower_bound(a+1,a+1+n,v[i])-a;
		f[x]++;f[y]++;marge(x,y);
	}
	for (int i=1;i<=n;i++){
		ans+=f[i]&1;
		if (a[i-1]<a[i]) num+=(!hsh[getfa(i)]),hsh[fa[i]]++;
	}
	if ((ans==0||ans==2)&&num<=1) printf("Possible");else printf("Impossible");
	return 0;
}













/*
典型的欧拉路，一笔画问题
但是要注意森林的情况
还有可能连一根棍子都没有 
*/
