#include<cstdio>
const int maxn=100005,tt=1000003;
int n;
int lnk[tt],nxt[maxn],son[maxn],tot;
inline int red(){
	int tot=0;char ch=getchar();
	while (ch<'0'||'9'<ch) ch=getchar();
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot;
}
struct ha{
	int s[7];
	bool operator==(const ha&b)const{
		ha c;
		for (int i=0;i<6;i++) c.s[i]=s[i];
		for (int t=0;t<6;t++){
			bool suc=1;
			for (int i=0;i<6;i++)
			 if (c.s[(i+t)%6]!=b.s[i]) {suc=0;break;}
			if (suc) return 1;
		}
		for (int i=0;i<6;i++) c.s[5-i]=s[i];
		for (int t=0;t<6;t++){
			bool suc=1;
			for (int i=0;i<6;i++)
			 if (c.s[(i+t)%6]!=b.s[i]) {suc=0;break;}
			if (suc) return 1;
		}
		return 0;
	}
}dat[maxn];
void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
bool check(int x,ha sim){
	for (int j=lnk[x];j;j=nxt[j])
	 if (dat[son[j]]==sim) return 1;
	return 0;
}
int main(){
	n=red();
	for (int i=1;i<=n;i++){
		int sum=0;
		for (int j=0;j<6;j++)
		 dat[i].s[j]=red(),sum+=dat[i].s[j];
		if (check(sum%tt,dat[i])) {printf("Twin snowflakes found.\n");return 0;}
		add(sum%tt,i);
	}
	printf("No two snowflakes are alike.\n");
	return 0;
}
