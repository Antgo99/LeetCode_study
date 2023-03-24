#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    TreeNode* traversal(vector<int>& nums,int left,int right){
        if(left >= right) return nullptr;
        int index=left;
        for(int i=left+1;i<right;i++){
            if(nums[index] < nums[i]) index = i;
        }
        int rootValue = nums[index];
        TreeNode* root = new TreeNode(rootValue);

        root->left = traversal(nums,left,index);
        root->right = traversal(nums,index+1,right);

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums,0,nums.size());
    }
};
