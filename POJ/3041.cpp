#include<cstdio>
#include<cstring>
const int maxn=505,maxe=10005;
int n,e,con[maxn],ans;
int son[maxe],nxt[maxe],lnk[maxn],tot;
bool vis[maxn];
inline int red(){
	int tot=0;char ch=getchar();
	while (ch<'0'||'9'<ch) ch=getchar();
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot;
}
void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
bool fnd(int x){
	for (int j=lnk[x];j;j=nxt[j])
	 if (!vis[son[j]]){
	 	vis[son[j]]=1;
	 	if (!con[son[j]]||fnd(con[son[j]])){
	 		con[son[j]]=x;return 1;
	 	}
	 }
	return 0;
}
int main(){
	n=red(),e=red();
	for (int i=1;i<=e;i++) add(red(),red());
	for (int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		ans+=fnd(i);
	}
	printf("%d",ans);
	return 0;
}













/*
�ȿȡ�������ͽ�����ο�������ͼƥ��ĺ���
����һ����ʯ������(x,y)���ǿ������Ϊ��
��ըx�л�y�ж������������ʯ��ʧ
��ô������к��п����������ϣ�ÿ����ʯ(x,y)����x����y�ı� 
������Ǻ�ը��y�У���ôy�������е���ʯ������ʧ��������ȥ���� 
���Ƶأ� ���Ѿ�ѡ��x~y�����ߣ���ô�κ���y�����ı߶������ٴ�����ʱ�������Ϊ��ը�˵�y�У� 
�ⲻ�������һ��ƥ�����к��й��ɵ��������ϲ����Ƕ���ͼ��
���ǵ�Ŀ����ǰ�������ʯ������ʹ�������Ĵ�������
��Ӧ����ͼ������B�㼯�У������б������ĵ㶼����ѡһ���ߣ�һ���͹��ˣ�����ƥ�� 
��ô���׵���hungary 
*/
