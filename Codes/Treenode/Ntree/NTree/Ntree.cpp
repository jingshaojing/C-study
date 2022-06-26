// N叉树的定义、层序遍历、前序遍历(递归版本，迭代版本）
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using  namespace std;
//  N叉树的定义
class node
{
public:
    int val;
    vector<node*> children;
    node() {}
    node(int _val)
    {
        val = _val;
    }
    node(vector<node*> _children)
    {
        children = _children;
    }
};
// 各个方法定义
class solution
{
public:
    // N叉树的层序遍历
    vector<vector<int> > level_traverseOfNtree(node* root)
    {
        queue<node*> que;
        if (root != nullptr) que.push(root);
        vector<vector<int>> result;
        while (!que.empty())
        {
            int size = que.size();
            vector<int> vec;
            for (int i = 0; i < size; i++)
            {
                node* temp = que.front();
                que.pop();
                vec.push_back(temp->val);
                // N叉树的孩子
                for (int j = 0; j < temp->children.size(); j++)
                {
                    que.push(temp->children[j]);
                }
            }
            result.push_back(vec);
        }
        return result;
    }
    // N叉树的前序遍历，递归

    vector<int> preOrder_Ntree(node* root)
    {
        result.clear();
        pre_traverse(root);
        return result;
    }
    // N叉树后序遍历
    vector<int> postOrder_Ntree(node* root)
    {
        result.clear();
        post_traverse(root);
        return result;
    }
    // 迭代版的N叉树前序遍历
    vector<int> preOrder_Ntree(node* root)
    {
        vector<int> result;
        stack<node*> sta;
        if (root != nullptr)
        {
            sta.push(root);
        }
        while (!sta.empty())
        {
            node* temp = sta.top();
            sta.pop();
            result.push_back(temp->val);
            for (int i = sta.size() -1; i >= 0 ; i++)
            {
                if (temp->children[i] != nullptr)
                {
                    sta.push(temp->children[i]);
                }
            }
        }
        return result;
    }
    // 迭代版N叉树的后序遍历
    vector<int> postOrder_Ntree(node* root)
    {
        vector<int> result;
        stack<node*> sta;
        if (root == nullptr) return result;
        sta.push(root);
        while (!sta.empty())
        {
            node* temp = sta.top();
            sta.pop();
            result.push_back(temp->val);
            for (int i = 0; i < temp->children.size(); i++)
            {
                if (temp->children[i] != nullptr)
                {
                    sta.push(temp->children[i]);
                }
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
    


private:
    vector<int> result;
    void pre_traverse(node* root)
    {
        if (root == NULL) return;
        result.push_back(root->val);
        for (int i = 0; i < root->children.size(); i++)
        {
            pre_traverse(root->children[i]);
        }
    }
    void post_traverse(node* root)
    {
        if (root == NULL) return;
        for (int i = 0; i < root->children.size(); i++)
        {
            post_traverse(root);
        }
        result.push_back(root->val);
    }
};
int  main()
{

}