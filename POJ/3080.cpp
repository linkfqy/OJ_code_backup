#include<cstdio>
const int maxn=15,maxs=65;
int tst,n;
char s[maxn][maxs];
bool check(int L,int R){
	int len=R-L;
	for (int i=2;i<=n;i++){
		bool suc=0;
		for (int j=0;j+len<60;j++){
			bool flg=1;
			for (int k=0;k<=len;k++)
			 if (s[1][k+L]!=s[i][k+j]) {flg=0;break;}
			if (flg) {suc=1;break;}
		}
		if (!suc) return 0;
	}
	return 1;
}
bool bigger(int i1,int i2,int len){
	for (int i=0;i<len;i++)
	 if (s[1][i1+i]>s[1][i2+i]) return 1;else
	 if (s[1][i1+i]<s[1][i2+i]) return 0;
	return 0;
}
int main(){
	scanf("%d",&tst);
	while (tst--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%s",s[i]);
		int len=0,L,R;
		for (int i=0;i<60;i++)
		 for (int j=i;j<60;j++)
		  if (check(i,j))
		   if (len<j-i+1||len==j-i+1&&bigger(L,i,j-i+1)) len=j-i+1,L=i,R=j;
		if (len<3) printf("no significant commonalities\n");else{
			for (int i=L;i<=R;i++) putchar(s[1][i]);putchar(10);
		}
	}
	return 0;
}













/*
要按字典序、要按字典序、要按字典序……
重要的事情说三遍 
*/
