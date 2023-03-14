/*
    二维数组dp数组01背包
    1.确定dp数组以及下标的含义
        dp[i][j]表示从下标为[0-i]的物品里任意取，放进容量为j的背包，价值总和最大是多少
    2.确定递推公式
        不放物品i:由dp[i-1][j]推出，即背包容量为j，里面不放物品i的最大价值，此时dp[i][j]就是dp[i-1][j]
        放物品i:由dp[i-1][j-weight[i]]推出，dp[i-1][j-weight[i]]为背包容量为j-weight[i]的时候不放物品i的最大价值，那么dp[i-1][j-weight[i]]+value[i]
        所以递归公式：dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i])
    3.dp数组初始化
        如果背包容量j为0，即dp[i][0],无论是选取哪些物品，背包价值总和一定为0
        dp[0][j],即i为0，存放编号0的物品的时候，各个容量的背包所能存放的最大价值
        那么很明显当j<weight[0]的时候，dp[0][j]应该是0，因为背包容量比编号0的物品重量还小
        当j>=weight[0]时，dp[0][j]应该是value[0],因为背包容量放足够放编号0物品
        for(int j=0;j<weight[0];j++){
            dp[0][j]=0;
        }
        //正序遍历
        for(int j=weight[0];j<=bagweight;j++){
            dp[0][j]=value[0];
        }

        //最终初始化代码
        vector<vector<int>> dp(weight.szie(),vector<int>(bagweight+1,0));
        for(int j=weight[0];j<=bagweight;j++){
            dp[0][j]=value[0];
        }
    4.确定顺序
        按照先遍历物品再遍历背包容量
        for(int i=1;i<weight.size();i++){
            for(int j=0;j<=bagweight;j++){
                if(j<weight[i]) dp[i][j]=dp[i-1][j];
                else dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
            }
        }

        按照先遍历背包，再遍历物品
        for(int j=0;j<=bagweight;j++){
            for(int i=1;i<weight.size();i++){
                if(j<weight[i]) dp[i][j]=dp[i-1][j];
                else dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
            }
        }    
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dp_backpack(){
    vector<int> weight={1,3,4};
    vector<int> value={15,20,20};
    int bagweight=4;

    vector<vector<int>> dp(weight.size(),vector<int>(bagweight+1,0));

    //初始化
    for(int j=weight[0];j<=bagweight;j++){
        dp[0][j]=value[0];
    }

    //weight数组的大小就是物品的个数
    for(int i=1;i<weight.size();i++){
        for(int j=0;j<=bagweight;j++){
            if(j<weight[i]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
        }
    }

    cout<<dp[weight.size()-1][bagweight]<<endl;
}

void scroll_backpack(){
    vector<int> weight={1,3,4};
    vector<int> value={15,20,20};
    int bagweight=4;

    vector<int> dp(bagweight+1,0);
    for(int i=0;i<weight.size();i++){
        for(int j=bagweight;j>=weight[i];j--){
            dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }
    cout<<dp[bagweight]<<endl;
}

int main(){
    dp_backpack();
    scroll_backpack();
    return 0;
}
