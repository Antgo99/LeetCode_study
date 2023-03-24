/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-20 14:47:16
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-20 15:19:31
 * @FilePath: \LeetCode\binary_tree\level_traversal\589.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    //递归
    void Recursive(Node* node,vector<int>& res){
        if(node == NULL) return;
        res.push_back(node->val);
        for(int i=0;i<node->children.size();i++){
            Recursive(node->children[i],res);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> res;
        Recursive(root,res);
        return res;
    }

    //迭代
    vector<int> preorder_2(Node* root){
        stack<Node*> st;
        vector<int> res;
        if(root != NULL) st.push(root);
        while(!st.empty()){
            Node* node = st.top();
            st.pop();
            res.push_back(node->val);
            for(int i=node->children.size()-1;i>=0;i--){//栈是先进后出，所以要从右向左将元素压入栈中
                st.push(node->children[i]);
            }
        }
        return res;
    }
};
