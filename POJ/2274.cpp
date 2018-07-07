#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=250005,tt=1000000;
int n,ans,x[maxn],v[maxn],num[105],len;
int lft[maxn],rit[maxn];
struct ha{
	int x,y;
	double Time,Dist;
	bool operator<(const ha&b)const{
		return Time<b.Time||Time==b.Time&&Dist<b.Dist;
	}
}hep[260005];
inline int red(){
	int tot=0;char ch=getchar();
	while (ch<'0'||'9'<ch) ch=getchar();
	while ('0'<=ch&&ch<='9') tot=tot*10+ch-48,ch=getchar();
	return tot;
}
void psh(ha x){
	hep[++len]=x;int son=len;
	while (son!=1&&hep[son]<hep[son>>1]) swap(hep[son>>1],hep[son]),son>>=1;
}
void pop(){
	hep[1]=hep[len--];int fa=1,son;
	while ((fa<<1)<=len){
		if ((fa<<1|1)>len||hep[fa<<1]<hep[fa<<1|1]) son=fa<<1;else son=fa<<1|1;
		if (hep[son]<hep[fa]) swap(hep[fa],hep[son]),fa=son;else break;
	}
}
double gettime(int i,int j){
	return (double)(x[j]-x[i])/(v[i]-v[j]);
}
double getdist(int i,int j){
	return gettime(i,j)*v[i]+x[i];
}
ha getha(int x,int y,double t,double d){
	ha res;
	res.x=x;res.y=y;res.Time=t;res.Dist=d;
	return res;
}
int main(){
	n=red();
	for (int i=1;i<=n;i++){
		x[i]=red(),v[i]=red();num[v[i]]++;
		for (int j=v[i]+1;j<=100;j++) ans=(ans+num[j])%tt;
		lft[i]=i-1;rit[i]=i+1;
		if (i>1&&v[i-1]>v[i]) psh(getha(i-1,i,gettime(i-1,i),getdist(i-1,i)));
	}v[0]=-1;v[n+1]=200;
	printf("%d\n",ans);
	for (int o=1;len&&o<=10000;o++){
		while (len&&rit[hep[1].x]!=hep[1].y) pop();
		if (!len) break;
		ha now=hep[1];pop();
		printf("%d %d\n",now.x,now.y);
		int lx=lft[now.x],ry=rit[now.y];
		rit[lx]=now.y;lft[ry]=now.x;
		lft[now.y]=lx;rit[now.y]=now.x;
		rit[now.x]=ry;lft[now.x]=now.y;
		if (v[lx]>v[now.y]) psh(getha(lx,now.y,gettime(lx,now.y),getdist(lx,now.y)));
		if (v[now.x]>v[ry]) psh(getha(now.x,ry,gettime(now.x,ry),getdist(now.x,ry)));
	}
	return 0;
}



/*
��һ�ʺܼ򵥣����͵�������������v��С�����������������״���飩�� 
���ڵڶ��ʣ�Ҫ��˳�����ǰ10000������Խ�¼�������Ȼ���뵽�ö������桰��Խ�¼���������ʹ���˶���ѣ� 
�����������������λ�� 
ÿ�δӶ���ȡ��һ����Խ�¼���ע���п����ǷǷ��ģ����ó�Խ�¼��������������Ѿ��������ˣ� 
Ȼ���Ҫ�������Խ�¼����д��� 
ԭ��������������lx,x,y,ry 
��Խ�����ˣ�lx,y,x,ry 
��ôlx��y��x��ry���п��ܷ����µġ���Խ�¼������ж�һ�·�����м��� 
*/
