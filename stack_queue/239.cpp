#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int left,right;
        int max;
        for(int i=0;i<=nums.size()-k;i++){
            left = i;
            right = i + k - 1;
            max = nums[left];
            while(left <= right){
                if(max < nums[left]) max = nums[left];
                left++;
            }
            res.push_back(max);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    vector<int> res = s.maxSlidingWindow(nums,3);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
    return 0;
}