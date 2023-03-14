/*
    20230313
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        //从(0,0)到(m-1,n-1)的路径次数
        vector<vector<int>> dp(m,vector<int>(n,0));//二维数组
        for(int i=0;i<m;i++) dp[i][0]=1;//下边界到达方式只有一种
        for(int j=0;j<n;j++) dp[0][j]=1;//上边界到达方式只有一种
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }

    //一维数组
    int uniquePaths_dimensional(int m, int n){
        vector<int> dp(n,0);
        for(int i=0;i<n;i++) dp[i]=1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[j] += dp[j-1];
            }
        }
        return dp[n-1];
    }
};

int main(){
    int m,n;
    while(true){
        cin>>m>>n;
        Solution s;
        cout<<s.uniquePaths_dimensional(m,n)<<endl;
    }
    return 0;
}
