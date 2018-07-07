#include<cstdio>
const int maxn=15;
const char p[2][7]={"KQRBNP","kqrbnp"};
char a[maxn][maxn];
bool fst;
void init(){
	char ch;int tot=0,i=1,j=0;
	while (i<=8){
		ch=getchar();
		if (ch=='|'){
			if (j==8) i++,j=0;else j++,tot++;
			continue;
		}
		if ((ch<'a'||'z'<ch)&&(ch<'A'||'Z'<ch)) continue;
		a[i][j]=ch;
	}
}
void print(char c,int x,char ch){
	if (fst) printf("%c%c%d",c,ch,x),fst=0;
	else printf(",%c%c%d",c,ch,x);
}
void print(int x,char ch){
	if (fst) printf("%c%d",ch,x),fst=0;
	else printf(",%c%d",ch,x);
}
void fnd(char ch,bool t){
	if (!t){
	for (int i=8;i>=1;i--)
	 for (int j=1;j<=8;j++)
	  if (a[i][j]==ch){
	  	a[i][j]=0;
		if (ch!='P') print(ch,8-i+1,j-1+'a');
		else print(8-i+1,j-1+'a');
	  }}else
	for (int i=1;i<=8;i++)
	 for (int j=1;j<=8;j++)
	  if (a[i][j]==ch){
	  	a[i][j]=0;
		if (ch!='p') print(ch-'a'+'A',8-i+1,j-1+'a');
		else print(8-i+1,j-1+'a');
	  }
}
int main(){
	init();
	fst=1;
	printf("White: ");
	for (int i=0;i<6;i++) fnd(p[0][i],0);
	printf("\nBlack: ");fst=1;
	for (int i=0;i<6;i++) fnd(p[1][i],1);
	return 0;
}
