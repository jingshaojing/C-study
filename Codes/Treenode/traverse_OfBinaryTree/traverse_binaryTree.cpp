// ���ֶ������ı���
// ˳�������ַ�ʽ����������

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct Treenode
{
    int val;
    Treenode* left;
    Treenode* right;
    Treenode() : val(0),left(nullptr),right(nullptr) {}
    Treenode(int x) : val(x), left(nullptr),right(nullptr) {}
    Treenode(int x, Treenode* left, Treenode* right) : val(x), left(left), right(right) {}
};
class solution
{
public:
    // �������
    void inorder_traverse(Treenode* cur, vector<int> &vec)
    {
        if (cur == nullptr) return;
        inorder_traverse(cur->left,vec);
        vec.push_back(cur->val);
        inorder_traverse(cur->right, vec);
    }
    // ǰ�����
    void preorder_traverse(Treenode* cur, vector<int>& vec)
    {
        if (cur == nullptr) return;
        vec.push_back(cur->val);
        preorder_traverse(cur->left, vec);
        preorder_traverse(cur->right, vec);
     }
    // �������
    void postorder_traverse(Treenode* cur, vector<int>& vec)
    {
        if (cur == nullptr) return;
        postorder_traverse(cur->left, vec);
        postorder_traverse(cur->right, vec);
        vec.push_back(cur->val);
    }
    vector<int> preOrderTraverse_iteration(Treenode* root)
    {
        vector<int> result;
        stack<Treenode*> sta;
        if (root != nullptr)
        {
            sta.push(root);
        }
        while (!sta.empty())
        {
            Treenode* temp = sta.top();
            if (temp != NULL)
            {
                sta.pop();
                if (temp->right) sta.push(temp->right);
                if (temp->left)  sta.push(temp->left);
                sta.push(temp);
                sta.push(NULL);
            }
            else
            {
                sta.pop();
                temp = sta.top();
                sta.pop();
                result.push_back(temp->val);
            }
        }
        return result;
    }
    // �������������
    vector<int> inOrderTraverse_iteration(Treenode* root)
    {
        vector<int> result;
        stack<Treenode*> sta;
        if (root != nullptr)
        {
            sta.push(root);
        }
        while (!sta.empty())
        {
            Treenode* temp = sta.top();
            if (temp != NULL)
            {
                sta.pop();
                if (temp->right) sta.push(temp->right);
                sta.push(temp);
                sta.push(NULL);
                if (temp->left) sta.push(temp->left);
            }
            else
            {
                sta.pop();
                temp = sta.top();
                sta.pop();
                result.push_back(temp->val);
            }
        }
        return result;
    }
    // ��������������
    vector<int> postOrderTraverse(Treenode* root)
    {
        vector<int> result;
        stack<Treenode*> sta;
        if (root != nullptr)
        {
            sta.push(root);
        }
        while (!sta.empty())
        {
            Treenode* temp = sta.top();
            if (temp != NULL)
            {
                sta.pop();
                sta.push(temp);
                sta.push(NULL);
                if (temp->left) sta.push(temp->left);
                if (temp->right) sta.push(temp->right);
            }
            else
            {
                sta.pop();
                temp = sta.top();
                sta.pop();
                result.push_back(temp->val);
            }
        }
        return result;
    }
    vector<int> traverse(Treenode* root)
    {
        vector<int> result;
        inorder_traverse(root, result);
        //preorder_traverse(root, result);
        //postorder_traverse(root, result);
    }
    // ��������ͺ���������������
    Treenode* traverse_creatTree(vector<int>& inorder, vector<int>& postorder)
    {
        if (postorder.size() == 0) return NULL;
        int rootvalue = postorder[postorder.size() - 1];
        Treenode* root = new Treenode(rootvalue);
        if (postorder.size() == 1) return root;
        // ��ֵ���붨�������棬��Ȼ����forѭ����ʧЧ
        int delimeterIndex;
        for (delimeterIndex = 0; delimeterIndex < inorder.size(); delimeterIndex++)
        {
            if (inorder[delimeterIndex] == rootvalue) break;
        }
        postorder.resize(postorder.size() - 1);
        vector<int> left_inorder(inorder.begin(), inorder.begin() + delimeterIndex);
        vector<int> right_inorder(inorder.begin() + delimeterIndex + 1, inorder.end());
        // ������������������С�����������������
        vector<int> left_postorder(postorder.begin(), postorder.begin() + left_inorder.size());
        vector<int> right_postorder(postorder.begin() + left_inorder.size(), postorder.end());
        // ��ʼ�ݹ����
        root->left = traverse_creatTree(left_inorder, left_postorder);
        root->right = traverse_creatTree(right_inorder, right_postorder);
        return root;      
    }
    // ���������
    Treenode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        if (inorder.size() == 0 || postorder.size() == 0) return NULL;
        return traverse_creatTree(inorder, postorder);
    }
};
int main()
{
    int number;
    vector<int> result;
    vector<int> inorder, postorder;
    while (cin >> number)
    {
        inorder.push_back(number);
        if (cin.get() == '\n') break;
    }
    while (cin >> number)
    {
        postorder.push_back(number);
        if (cin.get() == '\n') break;
    }
    Treenode* root = solution().buildTree(inorder, postorder);
    solution().postorder_traverse(root, result);
    for (auto ch : result)
    {
        cout << ch << " ";
    }
    return 0;
}