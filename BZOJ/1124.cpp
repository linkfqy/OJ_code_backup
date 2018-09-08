#include<cstdio>

const int maxn=1000005;
int n,to[maxn],f[maxn],fa[maxn],s[maxn],sum[maxn],MAX,MIN,que[maxn];
bool vis[maxn];
inline int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&to[i]),fa[i]=i,f[to[i]]++;
	for (int i=1;i<=n;i++) fa[getfa(to[i])]=getfa(i);
	for (int i=1;i<=n;i++) s[getfa(i)]+=(f[i]==0),sum[getfa(i)]++;
	for (int i=1;i<=n;i++)
	 if (getfa(i)==i){
	 	if (sum[i]==1) MAX++;else
	 	if (s[i]==0) MAX+=sum[i]-1;else MAX+=sum[i]-s[i];
	 }
	int hed=0,til=0;
	for (int i=1;i<=n;i++)
	 if (!f[i]) que[++til]=i,vis[i]=1;
	while (hed!=til){
		int x=que[++hed];
		if (!vis[to[x]]) vis[to[x]]=1,MIN++,f[to[to[x]]]--;
		if (!vis[to[to[x]]]&&!f[to[to[x]]]) que[++til]=to[to[x]],vis[to[to[x]]]=1;
	}
	for (int i=1;i<=n;i++) fa[i]=i,s[i]=0;
	for (int i=1;i<=n;i++)
	 if (!vis[i]&&!vis[to[i]]) fa[getfa(to[i])]=getfa(i);
	for (int i=1;i<=n;i++) if (!vis[i]) s[getfa(i)]++;
	for (int i=1;i<=n;i++)
	 if (getfa(i)==i) MIN+=s[i]+1>>1;
	printf("%d %d",MIN,MAX);
	return 0;
}
