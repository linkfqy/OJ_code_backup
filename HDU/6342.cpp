#include<cstdio>
#include<cstring>
using namespace std;
const int maxl=500;

int te,n;char s[maxl+5];

#define fsterr(L) (s[L]=='+'||s[L]=='*')
inline bool check(int L,int R){
    if (L>R) return true;if (fsterr(L)) return false;
    if (L==R) return true;if (s[L]=='0'&&s[L+1]!='?') return false;
    if (s[L]!='0') return true;s[L+1]='+';return check(L+2,R);
}
int main(){
    for (scanf("%d",&te);te;te--){
        scanf("%s",s+1);n=strlen(s+1);int lst=1;
        for (int i=1;i<n;i++) if (fsterr(i)&&fsterr(i+1)) goto END;
        if (fsterr(1)||fsterr(n)) goto END;
        for (int i=1;i<=n;i++)
            if (fsterr(i)) {if (!check(lst,i-1)) goto END;lst=i+1;}
        if (!check(lst,n)) goto END;
        for (int i=1;i<=n;i++) s[i]=='?'?s[i]='1':s[i];
        for (int i=1;i<n;i++) if (fsterr(i)&&fsterr(i+1)) goto END;
        if (fsterr(1)||fsterr(n)) goto END;
        for (int i=1;i<=n;i++) putchar(s[i]);puts("");
        continue;END:puts("IMPOSSIBLE");
    }
    return 0;
}
