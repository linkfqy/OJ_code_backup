#include<cstdio>
const int maxn=100005;
int n,q;
char s[maxn][15];
struct node{
	node *s[27];
	int cnt;
	node () {}
	node (int x):cnt(x) {}
}base[1200005],nil;
typedef node* P_node;
P_node null,len,Rot;
void Trie_init(){
	nil=node(0);null=&nil;len=base;
	for (int i=0;i<26;i++) null->s[i]=null;
}
P_node newnode(){
	*len=node(0);
	for (int i=0;i<26;i++) len->s[i]=null;
	return len++;
}
void ist(P_node &x,char *ch){
	if (x==null) x=newnode();
	x->cnt++;
	if (*ch==0) return;
	ist(x->s[*ch-'a'],ch+1);
}
int pre(P_node &x,char *ch){
	if (*ch==0) return x->cnt;
	return pre(x->s[*ch-'a'],ch+1);
}
int main(){
	Trie_init();Rot=newnode();
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%s",s[i]),ist(Rot,s[i]);
	scanf("%d",&q);
	for (int i=1;i<=q;i++){
		char str[15];scanf("%s",str);
		printf("%d\n",pre(Rot,str));
	}
	return 0;
}
