// �Ѷ���������תΪ˫������
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
        helper(root);  //�õ�һ��˫������headָ��ͷ���
        head->left = pre;
        pre->right = head;  //�γ�ѭ������
        return head;
    }
    void helper(Node* root) {
        if (root == NULL) return;
        helper(root->left);  //����������
        root->left = pre;
        if (pre != NULL) {
            pre->right = root;  //��ǰ�滹�нڵ��ʱ��������
        }
        else {
            head = root;  //���ǰ��û�нڵ��ˣ�֤����ͷ��㣬�͸���head
        }
        pre = root;
        helper(root->right);
    }
private:
    //pre��¼��һ���ڵ㣬headΪ��󷵻ص�ͷ���
    Node* head;
    Node* pre;
};
int main()
{
    return 0;
}