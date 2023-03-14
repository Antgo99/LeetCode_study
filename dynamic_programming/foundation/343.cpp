/*
    20230313
    刚开始没有思路，不知道该怎么写dp公式，即dp数组定义时的模糊

    题解：
        拆分一个数n，要使得乘积最大，那么一定是拆分成m个近似相同的子数相乘才是最大的
        1.dp[i]为拆分数字i的最大乘积
        2.递推公式：对于数字i来说，取得乘积的最大值有两个方式
            2.1 j*(i-j) 即将数字i拆分成两个数相乘
            2.2 j*dp[i-j] 将数字i-j又拆分成其他的数字乘积的方式
            dp[i]=max(dp[i],max(j*(i-j),j*dp[i-j]))
        3.初始化
            只有从数字2开始拆分才有意义
            所以dp[2]=1
        时间复杂度：O(n^2)
        空间复杂度：O(n)
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[2]=1;
        for(int i=3;i<=n;i++){
            for(int j=1;j<=i/2;j++){
                dp[i] = max(dp[i],max(j*(i-j),j*dp[i-j]));
            }
        }
        return dp[n];
    }
};
