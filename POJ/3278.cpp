#include<cstdio>
const int maxn=300005;
int stt,gl,que[maxn],f[maxn];
bool vis[maxn];
bool check(int x){
	return 0<=x&&x<=300000&&!vis[x];
}
void bfs(){
	int hed=0,til=1;
	que[1]=stt;vis[stt]=1;
	if (stt==gl) {printf("0");return;}
	while (hed!=til){
		int x=que[++hed];
		if (check(x+1)) que[++til]=x+1,vis[x+1]=1,f[x+1]=f[x]+1;
		if (que[til]==gl) {printf("%d",f[que[til]]);break;}
		if (check(x-1)) que[++til]=x-1,vis[x-1]=1,f[x-1]=f[x]+1;
		if (que[til]==gl) {printf("%d",f[que[til]]);break;}
		if (check(x*2)) que[++til]=x*2,vis[x*2]=1,f[x*2]=f[x]+1;
		if (que[til]==gl) {printf("%d",f[que[til]]);break;}
	}
}
int main(){
	scanf("%d%d",&stt,&gl);
	bfs();
	return 0;
}

































/*
�򵥵�BFS������Ҫע��һ�¼��㣺
1.�����ߵ�0��
2.��Ŀ�в�δ˵�������ߵ��������Ƕ��٣������Թ����������200000
3.ע��N==K�����������������ˣ�����졭���� 
*/
