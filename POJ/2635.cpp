#include<cstdio>
const int maxn=1000005,h[4]={1,10,100,1000};
int l,p[maxn];
char s[105];
bool vis[maxn];
void make_prime(){
	vis[0]=vis[1]=1;
	for (int i=2;i<=1000000;i++)
	 if (!vis[i]){
	 	p[++p[0]]=i;
	 	for (int j=2;i*j<=1000000;j++) vis[i*j]=1;
	 }
}
int main(){
	make_prime();
	scanf("%s%d",s,&l);
	while (l){
		bool suc=1;
		for (int i=1;p[i]<l&&i<=p[0];i++){
			int sum=0,now=0,times=0;
			for (int j=0;s[j];j++){
				now=(now<<3)+(now<<1)+s[j]-48;times++;
				if (times==3) sum=(sum*1000+now)%p[i],now=times=0;
			}
			if (times) sum=(sum*h[times]+now)%p[i];
			if (!sum) {suc=0;printf("BAD %d\n",p[i]);break;}
		}
		if (suc) printf("GOOD\n");
		scanf("%s%d",s,&l);
	}
	return 0;
}

//#include<cstdio>
//const int maxn=1000005;
//int l,p[maxn];
//char s[105];
//bool vis[maxn];
//void make_prime(){
//	vis[0]=vis[1]=1;
//	for (int i=2;i<=1000000;i++)
//	 if (!vis[i]){
//	 	p[++p[0]]=i;
//	 	for (int j=2;i*j<=1000000;j++) vis[i*j]=1;
//	 }
//}
//int main(){
//	make_prime();
//	scanf("%s%d",s,&l);
//	while (l){
//		bool suc=1;
//		for (int i=1;p[i]<l&&i<=p[0];i++){
//			int sum=0;
//			for (int j=0;s[j];j++) sum=(sum*10+s[j]-48)%p[i];
//			if (!sum) {suc=0;printf("BAD %d\n",p[i]);break;}
//		}
//		if (suc) printf("GOOD\n");
//		scanf("%s%d",s,&l);
//	}
//	return 0;
//}



/*
这题直接做TLE，还要压位…… 
*/
