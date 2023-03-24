/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-20 20:26:27
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-20 20:53:25
 * @FilePath: \LeetCode\binary_tree\reverse\257.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
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
    //  需要回溯来确定路径 用递归来回溯
    void traversal(TreeNode* node,vector<int> path,vector<string>& res){
        path.push_back(node->val);
        //找到叶子结点
        if(node->left == NULL && node->right == NULL){
            string sPath;
            for(int i=0;i<path.size()-1;i++){
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size()-1]);
            res.push_back(sPath);
            return;
        }

        if(node->left){
            traversal(node->left,path,res);
            path.pop_back();//回溯
        }

        if(node->right){
            traversal(node->right,path,res);
            path.pop_back();//回溯
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        if(root == NULL) return res;
        traversal(root,path,res);
        return res;
    }
};
