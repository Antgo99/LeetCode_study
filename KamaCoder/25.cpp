//无向图
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int NUM = 105;
int graph[NUM][NUM];//邻接矩阵图
int dist[NUM];//节点到源节点之间的最短距离
int n,m;//n为节点数，m为边的数量


void Dijkstra(int srcNode,int dstNode){
    dist[srcNode] = 0;
    vector<bool> visited(n+1);
    while(1){
        int t=-1;
        for(int i=1;i<=n;i++){
            if(!visited[i] && (t == -1 || dist[i] < dist[t])){
                t = i;
            }
        }
        //非联通或找到x->y的最短路径
        if(t == -1 || visited[t] || dist[t] == INF || t == dstNode) break;
        visited[t] = true;
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                dist[i] = min(dist[i],dist[t]+graph[t][i]);
            }
        }
    }
    if(dist[dstNode] >= INF) cout<<"No path"<<endl;
    else cout<<dist[dstNode]<<endl;
}

int main(){
    while(cin>>n>>m){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                graph[i][j] = INF;
            }
        }
        for(int i=0;i<m;i++){
            int a,b,l;
            cin>>a>>b>>l;
            graph[a][b]=l;
            graph[b][a]=l;
        }
        int x,y;
        cin>>x>>y;
        for(int i=1;i<=n;i++){
            dist[i] = INF;
        }
        Dijkstra(x,y);
    }
    return 0;
}
