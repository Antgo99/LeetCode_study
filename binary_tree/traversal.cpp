/*
    二叉树的递归遍历
        递归三要素
            1.确定递归函数的参数和返回值
            2.确定终止条件
            3.确定单层递归的逻辑
*/

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//递归遍历
class Recursive{
public:
    //前序遍历 中左右
    void pre_order_traversal(TreeNode* cur,vector<int>& res){
        if(cur == NULL) return;
        res.push_back(cur->val);//中
        pre_order_traversal(cur->left,res);//左
        pre_order_traversal(cur->right,res);//右
    }

    //中序遍历 左中右
    void mid_order_traversal(TreeNode* cur,vector<int>& res){
        if(cur == NULL) return;
        mid_order_traversal(cur->left,res);//左
        res.push_back(cur->val);//中
        mid_order_traversal(cur->right,res);//右
    }

    //后序遍历 左右中
    void post_order_traversal(TreeNode* cur,vector<int>& res){
        if(cur == NULL) return;
        post_order_traversal(cur->left,res);//左
        post_order_traversal(cur->right,res);//右
        res.push_back(cur->val);//中
    }

    vector<int> My_traversal(TreeNode* root){
        vector<int> res;
        pre_order_traversal(root,res);
        return res;
    }
};

//迭代遍历
class Iterate{
public:
    //前序遍历 先放入根节点，再放入右孩子节点，最后放入左孩子节点
    vector<int> pre_order_iterate(TreeNode* root){
        stack<TreeNode*> st;
        vector<int> res;
        if(root == NULL) return res;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();//中
            st.pop();
            res.push_back(node->val);
            if(node->right) st.push(node->right);//右
            if(node->left) st.push(node->left);//左
        }
        return res;
    }

    //中序遍历
    vector<int> mid_order_iterate(TreeNode* root){
        stack<TreeNode*> st;
        vector<int> res;
        TreeNode* cur = root;

        while(cur != NULL || !st.empty()){
            //指针访问节点，访问到最底层
            if(cur != NULL){
                st.push(cur);
                cur = cur->left;//左
            }else{
                cur = st.top();
                st.pop();
                res.push_back(cur->val);//中
                cur = cur->right;//右
            }
        }
        return res;
    }

    //后续遍历
    vector<int> post_order_iterate(TreeNode* root){
        stack<TreeNode*> st;
        vector<int> res;
        if(root == NULL) return res;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();//中
            st.pop();
            res.push_back(node->val);
            if(node->left) st.push(node->left);//左
            if(node->right) st.push(node->right);//右
        }
        reverse(res.begin(),res.end());//反转之后就是左右中
        return res;
    }
};

//统一迭代遍历
class unification_iterate{
public:
    //前序遍历
    vector<int> pre_order_traversal(TreeNode* root){
        stack<TreeNode*> st;
        vector<int> res;
        if(root != NULL) st.push(root);
        while(!st.empty()){
            TreeNode* cur = st.top();
            if(cur != NULL){
                st.pop();
                if(cur->right) st.push(cur->right);//右
                if(cur->left) st.push(cur->left);//左
                st.push(cur);//中
                st.push(NULL);
            }else{
                st.pop();
                cur = st.top();
                st.pop();
                res.push_back(cur->val);
            }
        }
        return res;
    }

    //中序遍历
    vector<int> mid_order_traversal(TreeNode* root){
        stack<TreeNode*> st;
        vector<int> res;
        if(root != NULL) st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            if(node != NULL){
                st.pop();//将节点弹出，再按照右中左的顺序添加节点
                if(node->right) st.push(node->right);//右节点
                st.push(node);//中节点
                st.push(NULL);
                if(node->left) st.push(node->left);//左节点
            }else{
                st.pop();//将空节点弹出
                node = st.top();//重新获取元素
                st.pop();
                res.push_back(node->val);
            }
        }
        return res;
    }

    //后序遍历
    vector<int> post_order_traversal(TreeNode* root){
        stack<TreeNode*> st;
        vector<int> res;
        if(root != NULL) st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            if(node != NULL){
                st.pop();
                st.push(node);
                st.push(NULL);
                if(node->right) st.push(node->right);
                if(node->left) st.push(node->left);
            }else{
                st.pop();
                node = st.top();
                st.pop();
                res.push_back(node->val);
            }
        }
        return res;
    }
};

/*层次遍历
    栈 先进后出 符合深度优先遍历
    队列 先进先出 符合广度优先遍历
*/
class level{
public:
    vector<vector<int>> level_order_traversal(TreeNode* root){
        queue<TreeNode*> que;
        vector<vector<int>> res;
        if(root != NULL) que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> path;
            //使用固定大小的size,不能使用que.size(),因为que.size()是不断变化的
            for(int i=0;i<size;i++){
                TreeNode* node = que.front();
                que.pop();
                path.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.push_back(path);
        }
        return res;
    }

    //递归法
    void order(TreeNode* cur,vector<vector<int>>& res,int depth){
        if(cur == NULL) return;
        if(res.size() == depth) res.push_back(vector<int>());
        res[depth].push_back(cur->val);
        order(cur->left,res,depth+1);
        order(cur->right,res,depth+1);
    }

    vector<vector<int>> level_order_traversal_Recursive(TreeNode* root){
        vector<vector<int>> res;
        int depth = 0;
        order(root,res,depth);
        return res;
    }
};
