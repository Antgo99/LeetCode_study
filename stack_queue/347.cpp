/*
  利用小顶堆的经典题目
  统计元素出现的频率，并找出前k个出现次数最多的元素
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
    class My_compare{
    public:
        bool operator()(pair<int,int>& lhs,pair<int,int>& rhs){
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        vector<int> res(k);
        //统计元素出现的频率用map
        for(int i=0;i<nums.size();i++){
            um[nums[i]]++;
        }

        //对元素的频率进行排序——维护一个k大小的小顶堆
        priority_queue<pair<int,int>,vector<pair<int,int>>,My_compare> pq;
        for(auto it=um.begin();it!=um.end();it++){
            pq.push(*it);
            if(pq.size() > k) pq.pop();
        }

        //找出前k个高频的元素
        for(int i=k-1;i>=0;i--){
            res[i] = pq.top().first;
            pq.pop();
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums={1,1,2,2,2,3};
    vector<int> res=s.topKFrequent(nums,2);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
    return 0;
}
