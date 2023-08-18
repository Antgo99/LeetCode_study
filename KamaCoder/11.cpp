#include<bits/stdc++.h>
using namespace std;

const int NUM = 105;
int graph[NUM][NUM];

int main(){
    int n;
    while(cin>>n){
        int Max = 0;
        memset(graph,0,sizeof(graph));
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            graph[a][b] = 1;
            Max = max(max(a,b),Max);
        }
        int father_index = 0;
        for(int j=1;j<=Max;j++){
            int count = 0;
            for(int i=1;i<=Max;i++){
                if(graph[i][j] == 1){
                    count++;
                }
            }
            if(count == 2){
                father_index = j;
                break;
            }
        }
        int row_ming = 1,row_yu = 2,ming_number = 0,yu_number = 0;
        while(1){
            for(int j=1;j<=Max;j++){
                if(graph[row_ming][j] == 1){
                    row_ming = j;
                    ming_number++;
                    break;
                }
            }
            for(int j=1;j<=Max;j++){
                if(graph[row_yu][j] == 1){
                    row_yu = j;
                    yu_number++;
                    break;
                }
            }
            if(row_ming == father_index && row_yu == father_index) break;
        }
        if(ming_number > yu_number) cout<<"You are my elder"<<endl;
        else if(ming_number == yu_number) cout<<"You are my brother"<<endl;
        else cout<<"You are my younger"<<endl;
    }
    return 0;
}
