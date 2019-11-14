#include "bits/stdc++.h"

using namespace std;

/**<Floyd�㷨�Ƕ�Դ���·�㷨�����Ӷ���ߣ�n^3����ͨ�����ڵ�Ƚ��ٵ���㲻�̶��������С��ܽ�����ߣ���Ȩ�������ܽ������*/
/**#define MAX 65535
const int N;
int chara[N][N];
int p[N][N];
int n;
void Folyd(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            p[i][j] = j;
        }
    }
    for(int k = 1; k<= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j<=n; ++j){
                if(chara[i][k] == MAX || chara[k][j] == MAX)
                    continue;
                if(chara[i][j] < chara[i][k] + chara[k][j]){
                    chara[i][j] = chara[i][k] + chara[k][j];
                    p[i][j] = p[i][k];
                }
            }
        }
    }
}
*/


///Dijkstra�㷨
/**#define MAX 65535
const int N;
int chara[N][N],dis[N];
int p[N],vis[N];
int n;
void Dijkstra(int src){
    for(int i = 1; i <=n ; ++i){
        dis[i] = chara[src][i];
        p[i] = 0;
        vis[i] = 0;
    }
    vis[src] = 1;
    dis[src] = 0;
    for(int i = 1; i <= n; ++i){
        int k,ans = MAX;
        for(int j = 1; j <= n; j++){
            if(vis[j] && dis[j] <ans){
                k = j;
                ans = dis[j];
            }
        }
        vis[k] = 1;
        if(ans == MAX) break;
        for(int j = 1; j <= n; ++j){
            if(!vis[j] && dis[j] < dis[k] + chara[k][j]){
                dis[j] = dis[k] + chara[k][j];
                p[j] = k;
            }
        }
    }
}
*/

///SPFA�㷨    ����жϳɻ����ڴ����ʱ����¼��ÿ�������ȣ�ÿ������ӵ�ʱ���¼һ�Σ������ӵĴ���������������ȣ�˵����ĳһ��·���������Σ����õ㴦�ɻ���
/**const int INF = 0x3f3f3f3f;
const int N;
int n;
int d[N], vis[N];
struct node{
    int v; //��
    int weight; //Ȩֵ
};
vector<node> mp[N];
void SPFA(int src){
    int q;
    queue<int> Q;
    vis[src] = 1;
    dis[src] = 0;
    Q.push(src);
    while(!Q.empty()){
        q = Q.front();
        Q.pop();
        vis[q] = 0;
        for(int i = 0; i < mp[q].size(); ++i){
            if(dis[q] + mp[q][i].weight < dis[mp[q][i].v)
            {
                dis[mp[q][i].v] = dis[q] + mp[q][i].weight;
                if(!vis[mp[q][i].v)
                {
                    Q.push(mp[q][i].v);
                    vis[mp[q][i].v] = 1;
                }
            }
        }
    }
    return;
}*/


int main()
{
}
