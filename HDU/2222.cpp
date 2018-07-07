#include<cstdio>
#include<cstring>
#include<algorithm>
#define cl(x,y) memset(x,y,sizeof(x))
using namespace std;

const int maxn=1000005;
int tst,n,fal[maxn],son[maxn][26],sum[maxn],lst[maxn],ans,rot=1,len=1;
char s[maxn];
inline void clear(int x){
	cl(son[x],0);sum[x]=fal[x]=0;
}
void add_s(char *s){
	int x=rot;
	for (int i=0;s[i];i++){
		int c=s[i]-'a';
		if (!son[x][c]) son[x][c]=++len,clear(len);
		x=son[x][c];
	}
	sum[x]++;
}
int que[maxn];
void make_fail(){
	int hed=0,til=0;
	for (int c=0,u;c<26;c++)
	 if (u=son[rot][c]) que[++til]=u,fal[u]=lst[u]=rot;
	 else son[rot][c]=rot;
	while (hed!=til){
		int x=que[++hed];
		for (int c=0,u;c<26;c++)
		 if (u=son[x][c]){
		 	que[++til]=u,fal[u]=son[fal[x]][c];
		 	if (sum[fal[u]]) lst[u]=fal[u];else lst[u]=lst[fal[u]];
		 }
		 else son[x][c]=son[fal[x]][c];
	}
}
void ask_s(char *s){
	for (int i=0,x=rot;s[i];i++){
		int c=s[i]-'a';x=son[x][c];
		for (int p=x;p!=rot&&sum[p]>=0;p=lst[p]) ans+=sum[p],sum[p]=-1;
	}
}
int main(){
	scanf("%d",&tst);
	while (tst--){
		scanf("%d",&n);
		rot=len=1;ans=0;
		cl(son,0);cl(fal,0);cl(sum,0);cl(lst,0);
		while (n--){
			scanf("%s",s);
			add_s(s);
		}
		make_fail();
		scanf("%s",s);
		ask_s(s);
		printf("%d\n",ans);
	}
	return 0;
}
