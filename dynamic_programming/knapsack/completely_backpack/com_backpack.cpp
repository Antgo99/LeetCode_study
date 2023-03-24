#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dp_backpack(){
    vector<int> weight={1,3,4};
    vector<int> value={15,20,20};
    int bagweight=4;
    vector<int> dp(bagweight+1,0);
    for(int i=0;i<weight.size();i++){
        for(int j=weight[i];j<=bagweight;j++){
            dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }
    cout<<dp[bagweight]<<endl;
}

int main(){
    dp_backpack();
    return 0;
}
