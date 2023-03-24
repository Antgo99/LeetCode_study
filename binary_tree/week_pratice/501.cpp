/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-22 14:30:37
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-22 15:10:30
 * @FilePath: \LeetCode\binary_tree\week_practice\501.cpp
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
    //如果不是二叉搜索树 思路：用map来统计元素出现的频率并进行排序
    void searchBST(TreeNode* root,unordered_map<int,int>& map){
        if(root == NULL) return;
        map[root->val]++;
        searchBST(root->left,map);
        searchBST(root->right,map);
    }
    //定义排序的方式
    bool static cmp(pair<int,int>& a,pair<int,int>& b){
        return a.second > b.second;
    }

    vector<int> findMode(TreeNode* root){
        unordered_map<int,int> map;
        searchBST(root,map);
        vector<int> result;
        vector<pair<int,int>> res(map.begin(),map.end());
        sort(res.begin(),res.end(),cmp);//给频率排序
        result.push_back(res[0].first);
        for(int i=1;i<res.size();i++){
            if(res[i].second == res[0].second) result.push_back(res[i].first);
            else break;
        }
        return result;
    }

    //在二叉搜索树的情况下，用中序遍历出来的数组是有序的 这样在判断出现频率时候就只需要前后数是否相等
    int maxCount=0;
    int count=0;
    vector<int> res;
    TreeNode* preNode = NULL;
    void traversal(TreeNode* root){
        if(root == NULL) return;
        traversal(root->left);//左
        //中
        if(preNode == NULL){//根节点
            count = 1;
        }else if(preNode->val == root->val){//当前后节点相等的时候 频率加1
            count++;
        }else{
            count=1;
        }
        preNode = root;//更新上一个节点

        if(count == maxCount){//当前节点的频率等于最大频率时 加入到结果队列中
            res.push_back(root->val);
        }

        if(count > maxCount){
            maxCount = count;
            res.clear();
            res.push_back(root->val);
        }

        //右
        traversal(root->right);
    }

    vector<int> findMode(TreeNode* root){
        traversal(root);
        return res;
    }
};
