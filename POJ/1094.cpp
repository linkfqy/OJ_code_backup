#include<cstdio>
#include<cstring>
const int maxn=30;
int n,e,dep[maxn],f[maxn],t[maxn],que[maxn];
bool a[maxn][maxn],vis[maxn];
inline char fstchar(){
	char ch=getchar();
	while (ch<'A'||'Z'<ch) ch=getchar();
	return ch;
}
int topo(){
	memset(dep,0,sizeof(dep));
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++) f[i]=t[i];
	int hed=0,til=0;
	for (int i=1;i<=n;i++)
	 if (!f[i]) que[++til]=i,vis[i]=1,dep[i]=1;
	while (hed!=til){
		int x=que[++hed];
		for (int i=1;i<=n;i++)
		 if (a[x][i]){
		 	f[i]--;
		 	if (!vis[i]&&!f[i]) vis[i]=1,que[++til]=i,dep[i]=dep[x]+1;
		 }
	}
	if (til<n) return 2;
	if (dep[que[til]]==n) return 1;
	return 0;
}
void print(int id){
	printf("Sorted sequence determined after %d relations: ",id);
	for (int i=1;i<=n;i++) putchar(que[i]+'A'-1);
	printf(".\n");
}
int main(){
	scanf("%d%d",&n,&e);
	while (n){
		memset(a,0,sizeof(a));
		memset(t,0,sizeof(t));
		bool don=0;
		for (int i=1;i<=e;i++){
			int x=fstchar()-'A'+1,y=fstchar()-'A'+1;
			if (don) continue;
			a[x][y]=1;t[y]++;int zc=topo();
			if (zc==1) print(i),don=1;else  //ȷ�� 
			if (zc==2) printf("Inconsistency found after %d relations.\n",i),don=1;  //ì�� 
		}
		if (!don) printf("Sorted sequence cannot be determined.\n");  //��ȷ�� 
		scanf("%d%d",&n,&e);
	}
}










/*
��Ȼ��ˢe�����˾Ϳ��Եõ���
�ѵ����ڣ�����ж�3�������
1.����ì�ܣ���Ȼ����til<n���ж�
2.ȷ����������Ŀ�������ԣ����Կ϶���ʱͼ����һ�����ظ��ģ��ᴩ����ͼ�������Դ��жϼ���
3.��ȷ����ʣ�µĿ϶��ǲ�ȷ��
ֵ��ע����ǣ�����������У��ж�ì��Ӧ���ȣ������������ 
*/
