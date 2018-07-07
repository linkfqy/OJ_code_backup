#include<cstdio>
#include<cstring>
const int maxn=105,p[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
int tst,n,m,k,q,num[128],mp[maxn][maxn];
struct robot{
	int x,y,t,id;
	void read(){
		char ch;
		scanf("%d%d%*c%c",&y,&x,&ch);
		t=num[ch];mp[x][y]=id;
	}
	void lft(int num){
		t=(t+num)%4;
	}
	void rit(int num){
		t=(t-num+4)%4;
	}
	int frt(int num){
		mp[x][y]=0;
		while (num--){
			x+=p[t][0];y+=p[t][1];
			if (mp[x][y]) return mp[x][y];
			if (x<1||y<1||x>n||y>m) return -1;
		}
		mp[x][y]=id;
		return 0;
	}
}a[maxn];
int main(){
	num['S']=1;num['E']=2;num['N']=3;
	scanf("%d",&tst);
	while (tst--){
		memset(mp,0,sizeof(mp));
		scanf("%d%d%d%d",&m,&n,&k,&q);
		for (int i=1;i<=k;i++) a[i].id=i,a[i].read();
		bool suc=1;
		for (int i=1;i<=q;i++){
			char ch;int x,times;
			scanf("%d%*c%c%d",&x,&ch,&times);
			if (!suc) continue;
			if (ch=='L') a[x].lft(times%4);else
			if (ch=='R') a[x].rit(times%4);else{
				int zc=a[x].frt(times);
				if (zc<0) suc=0,printf("Robot %d crashes into the wall\n",x);else
				if (zc>0) suc=0,printf("Robot %d crashes into robot %d\n",x,zc);
			}
		}
		if (suc) printf("OK\n");
	}
	return 0;
}
