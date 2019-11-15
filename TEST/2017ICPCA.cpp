#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,x,a[1009],b[1009];
    while(scanf("%d%d%d",&m,&n,&x) != EOF){
        memset(b,0,sizeof(b));
        for(int i = 1; i <= n; i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+1+n);
        int cnt = m;
        for(int i = 1; i <= x; i++){
            for(int j = 1; j <= n; j++){
                if(b[j] == 0) cnt--;
                if(i % a[j] == 0) b[j] = 0;
                else if(cnt >= 0)b[j] = 1;
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(b[i] == 1) ans++;
        }
        if(cnt >0)
        printf("%d %d\n",cnt,ans);
        else
            printf("0 %d\n",ans);
    }
    return 0;
}
