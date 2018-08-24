#include<cstdio>

const int maxn=1000006;
int n,son[maxn][2];
char s[maxn][5];
bool w[maxn],f[maxn];
void getw(int x){
	if (s[x][0]=='A'){
		getw(son[x][0]); getw(son[x][1]);
		w[x]=(w[son[x][0]]&&w[son[x][1]]);
	}else
	if (s[x][0]=='O'){
		getw(son[x][0]); getw(son[x][1]);
		w[x]=(w[son[x][0]]||w[son[x][1]]);
	}else
	if (s[x][0]=='X'){
		getw(son[x][0]); getw(son[x][1]);
		w[x]=(w[son[x][0]]^w[son[x][1]]);
	}else
	if (s[x][0]=='N'){
		getw(son[x][0]); w[x]=(!w[son[x][0]]);
	}
}
void dp(int x){
	if (!f[x]) return;
	if (s[x][0]=='A'){
		if (w[son[x][0]]) f[son[x][1]]=1;
		if (w[son[x][1]]) f[son[x][0]]=1;
		dp(son[x][0]); dp(son[x][1]);
	}else
	if (s[x][0]=='O'){
		if (!w[son[x][0]]) f[son[x][1]]=1;
		if (!w[son[x][1]]) f[son[x][0]]=1;
		dp(son[x][0]); dp(son[x][1]);
	}else
	if (s[x][0]=='X'){
		f[son[x][1]]=1;f[son[x][0]]=1;
		dp(son[x][0]); dp(son[x][1]);
	}else
	if (s[x][0]=='N'){
		f[son[x][0]]=1;
		dp(son[x][0]);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1,x;i<=n;i++){
		scanf("%s",s[i]);
		if (s[i][0]=='I') scanf("%d",&x),w[i]=(x==1);else
		if (s[i][0]=='N') scanf("%d",&son[i][0]);else
		 scanf("%d%d",&son[i][0],&son[i][1]);
	}
	getw(1);
	f[1]=1; dp(1);
	for (int i=1;i<=n;i++)
	 if (s[i][0]=='I') putchar((f[i]^w[1])?'1':'0');
	return 0;
}
