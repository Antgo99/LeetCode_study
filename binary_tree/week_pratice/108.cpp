/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-22 20:48:52
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-22 21:19:38
 * @FilePath: \LeetCode\binary_tree\week_practice\108.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    TreeNode* traversal(vector<int>& nums,int left,int right){
        if(left >= right) return NULL;
        int index = left + (right - left)/2;//如果是偶数会取靠左边的元素
        int rootValue = nums[index];
        TreeNode* root = new TreeNode(rootValue);

        root->left = traversal(nums,left,index);
        root->right = traversal(nums,index+1,right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return traversal(nums,0,nums.size());
    }
};
