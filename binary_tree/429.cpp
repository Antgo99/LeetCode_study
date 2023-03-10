#include<iostream>
#include<queue>
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
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
        vector<vector<int>> res;
        if(root != NULL) que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> path;
            for(int i=0;i<size;i++){
                Node* cur = que.front();
                que.pop();
                path.push_back(cur->val);
                for(int j=0;j<cur->children.size();j++){//孩子节点变多了 那就遍历来取
                    if(cur->children[j]) que.push(cur->children[j]);
                }
            }
            res.push_back(path);
        }
        return res;
    }
};
