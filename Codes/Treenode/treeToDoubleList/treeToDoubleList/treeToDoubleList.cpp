// 把二叉搜索树转为双向链表
#include <iostream>

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == NULL) return NULL;
        helper(root);  //得到一个双向链表，head指向头结点
        head->left = pre;
        pre->right = head;  //形成循环链表
        return head;
    }
    void helper(Node* root) {
        if (root == NULL) return;
        helper(root->left);  //规整左子树
        root->left = pre;
        if (pre != NULL) {
            pre->right = root;  //当前面还有节点的时候，连接上
        }
        else {
            head = root;  //如果前面没有节点了，证明是头结点，就更新head
        }
        pre = root;
        helper(root->right);
    }
private:
    //pre记录上一个节点，head为最后返回的头结点
    Node* head;
    Node* pre;
};
int main()
{
    return 0;
}