#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100005,maxk=33,tt=1000003;
int n,k,ans=0;
int lnk[tt],nxt[maxn],son[maxn],tot;
void add(int x,int y){
	son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
struct ha{
	int s[maxk];
}dat[maxn],m[maxn];
inline int red(){
	int tot=0;char ch=getchar();
	while (ch<'0'||'9'<ch) ch=getchar();
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot;
}
int fnd(int x,int sim){
	for (int j=lnk[x];j;j=nxt[j]){
		bool suc=1;
		for (int i=0;i<k;i++)
		 if (m[son[j]].s[i]!=m[sim].s[i]) {suc=0;break;}
		if (suc) return son[j];
	}
	return -1;
}
int main(){
	n=red(),k=red();add(0,0);
	for (int i=1;i<=n;i++){
		int x=red(),sum=0,Min=0x3f3f3f3f;
		for (int j=0;j<k;j++)
		 dat[i].s[j]=dat[i-1].s[j]+((x&(1<<j))!=0),
		 Min=min(Min,dat[i].s[j]);
		for (int j=0;j<k;j++)
		 m[i].s[j]=dat[i].s[j]-Min,
		 sum=(sum*7+m[i].s[j])%tt;
		x=fnd(sum,i);
		if (x<0) add(sum,i);else ans=max(ans,i-x);
	}
	printf("%d",ans);
	return 0;
}



















/*
��Ŀ���⣺��һ�����䣬ʹ������������������������ƣ���ÿһλ1�ĸ������
���Զ�ÿһλ����ǰ׺�ͣ� ö��һ��i����Ϊ������յ㣬��Ŀ��ת���ɣ�
����С��j��ʹ��s[i][0]-s[j][0]==s[i][1]-s[j][1]==����
�����s[i]��s[j]�ֱ�����һ������ͳ��ͼ���ᷢ������ͼ����״����ͬ�ģ�ֻ��ÿ����ĸ߶Ȳ�ͬ�� 
��ô������ʵ���ǣ�Ѱ����״��ͬ�ģ���֮ǰ���ֹ���s[j]
��ô�Ϳ����õ���ϣ��s[j]-Min{s[j]}����ͬ��״��ͼ�ͱ��һģһ����
��ϣ����Ѱ�Ҽ��� 
*/
