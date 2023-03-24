/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-20 17:29:00
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-20 19:35:01
 * @FilePath: \LeetCode\binary_tree\reverse\559.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

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
    int maxDepth(Node* root) {
        if(root == NULL) return 0;
        int depth=0;
        queue<Node*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            depth++;
            for(int i=0;i<size;i++){
                Node* node = que.front();
                que.pop();
                for(int j=0;j<node->children.size();j++){
                   if(node->children[j]) que.push(node->children[j]);
                }
            }
        }
        return depth;
    }
};
