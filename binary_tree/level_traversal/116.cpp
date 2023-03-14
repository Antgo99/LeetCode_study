/*
    20230313
    第一次做不知道如何处理返回值是树结构的结构体
    思路还是每次遍历每层，并且让前一个节点指向当前节点，在本层的最后一个节点添加空的即可
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
            Node* node;
            Node* nodePre;
            for(int i = 0;i < size;i++){
                //每一层的第一个节点
                if(i==0){
                    nodePre = que.front();
                    que.pop();
                    node = nodePre;
                }else{
                    node = que.front();
                    que.pop();
                    nodePre->next = node;//让本层的前一个节点next指向本节点
                    nodePre = nodePre->next;
                }
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            nodePre->next = NULL;//本层的最后一个节点指向NULL
        }
        return root;
    }
};
