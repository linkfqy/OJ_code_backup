#include<cstdio>
const int maxn=1005,maxs=25005;
int n;
char s[maxn][25];
struct node{
	node *s[26];
	int cnt;
	node () {}
	node (int a):cnt(a) {}
}nil,base[maxs];
typedef node* P_node;
P_node len,null,Rot;
void Trie_init(){
	nil=node(0);null=&nil;len=base;
	for (int i=0;i<26;i++) null->s[i]=null;
}
P_node newnode(){
	*len=node(0);
	for (int i=0;i<26;i++) len->s[i]=null;
	return len++;
}
void ist(P_node &x,char *c){
	if (x==null) x=newnode();
	x->cnt++;
	if (*c==0) return;
	ist(x->s[*c-'a'],c+1);
}
void pre(P_node x,char *c){
	if (*c==0) return;
	putchar(*c);
	if (x->s[*c-'a']->cnt==1) return;
	pre(x->s[*c-'a'],c+1);
}
int main(){
	Trie_init();Rot=newnode();n=0;
	while (~scanf("%s",s[++n])) ist(Rot,s[n]);
	n--;
	for (int i=1;i<=n;i++) printf("%s ",s[i]),pre(Rot,s[i]),putchar(10);
	return 0;
}
