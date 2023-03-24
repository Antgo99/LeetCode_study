/*
    20230315
    给定背包容量，装满背包最多有多少物品
    1.dp[i][j]:最多有i个0和j个1的strs的最大子集的大小为dp[i][j]
    0和1的个数相当于weight

*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(string st:strs){
            int zero_num=0,one_num=0;
            for(char ch:st){
                if(ch == '0') zero_num++;
                else one_num++;
            }
            for(int i=m;i>=zero_num;i--){//从后向前遍历
                for(int j=n;j>=one_num;j--){
                    dp[i][j] = max(dp[i][j],dp[i-zero_num][j-one_num]+1);
                }
            }
        }
        return dp[m][n];
    }
};

int main(){
    vector<string> strs={"10", "0001", "111001", "1", "0"};
    Solution s;
    int m,n;
    cin>>m>>n;
    cout<<s.findMaxForm(strs,m,n)<<endl;
    return 0;
}
