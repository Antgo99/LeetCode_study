/*
    20230313
    和116同一解法和代码
*/
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node(int x):val(x),left(nullptr),right(nullptr),next(nullptr){}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if(root != NULL) que.push(root);
        while(!que.empty()){
            int size = que.size();
            Node* nodePre;
            Node* node;
            for(int i=0;i<size;i++){
                if(i==0){
                    nodePre = que.front();
                    que.pop();
                    node = nodePre;
                }else{
                    node = que.front();
                    que.pop();
                    nodePre->next = node;
                    nodePre = nodePre->next;
                }
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            nodePre->next = NULL;
        }
        return root;
    }
};
