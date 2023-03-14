/*
    20230313
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;//初始化位置和终点位置有障碍的情况
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m && obstacleGrid[i][0] == 0;i++){
            dp[i][0]=1;
        }
        for(int j=0;j<n && obstacleGrid[0][j] == 0;j++){
            dp[0][j]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j] == 1) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main(){
    vector<vector<int>> res={{0,0,0},{0,1,0},{0,0,0}};
    Solution s;
    cout<<s.uniquePathsWithObstacles(res)<<endl;
    return 0;
}
