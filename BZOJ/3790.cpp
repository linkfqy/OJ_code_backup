#include<cstdio>
#include<algorithm>
#define mp make_pair
#define X first
#define Y second
using namespace std;

const int maxn=100005;
int n,p[maxn];
char t[maxn],s[maxn];
pair<int,int> a[maxn];
void manacher(char *s){
	int pos=0,R=0;
	for (int i=1;i<=n;i++){
		if (i<R) p[i]=min(p[2*pos-i],R-i); else p[i]=1;
		while (1<=i-p[i]&&i+p[i]<=n&&s[i-p[i]]==s[i+p[i]]) p[i]++;
		if (i+p[i]>R) pos=i,R=i+p[i];
		a[i]=mp(i-p[i]+1,i+p[i]-1);
	}
}
int main(){
	while (~scanf("%s",t+1)){
		n=0;
		for (int i=1;t[i];i++) s[++n]='#',s[++n]=t[i];
		s[++n]='#';
		manacher(s);
		sort(a+1,a+1+n);
		int ans=0;
		for (int i=1,j=1,MX=0;i<=n;){
			while (j<=n&&a[j].X<=i) MX=max(MX,a[j++].Y);
			i=MX+1;ans++;
		}
		printf("%d\n",ans-1);
	}
	return 0;
}
