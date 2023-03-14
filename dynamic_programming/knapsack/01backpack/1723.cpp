/*
    20230314
    困难难度
    动规转移方程式不太懂
    dp[i][j]表示给前i个人分配工作，工作的分配情况为j时，完成所有工作的最短时间。j是一个二进制整数，表示工作的分配情况
    状态转移方程的含义为：枚举j的每一个子集j',让其作为分配给工人i的工作，这样就需要给前i-1个人分配集合j中子集j'的补集
    最终dp[k-1][2^n-1]为答案
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<int> sum(1<<n);
        for(int i=1;i<(1<<n);i++){
            int x = __builtin_ctz(i),y=i-(1<<x);
            sum[i] = sum[y] + jobs[x];
        }

        vector<vector<int>> dp(k,vector<int>(1<<n));
        //初始化
        for(int i=0;i<(1<<n);i++){
            dp[0][i] = sum[i];
        }

        for(int i=1;i<k;i++){
            for(int j=0;j<(1<<n);j++){
                int min_time = INT_MAX;
                for(int x=j;x;x=(x-1)&j){
                    min_time = min(min_time,max(dp[i-1][j-x],sum[x]));
                }
                dp[i][j]=min_time;
            }
        }
        return dp[k-1][(1<<n)-1];
    }
};

int main(){
    vector<int> nums={1,3,5,1000};
    Solution s;
    cout<<s.minimumTimeRequired(nums,4)<<endl;
    return 0;
}
