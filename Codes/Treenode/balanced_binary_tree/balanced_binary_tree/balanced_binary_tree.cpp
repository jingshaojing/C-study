// ƽ������� ���������ĸ߶Ȳ�С��1
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
struct Treenode
{
    int val;
    Treenode* left;
    Treenode* right;
    Treenode():val(0),left(nullptr),right(nullptr) {}
    Treenode(int x) : val(x), left(nullptr),right(nullptr) {}
    Treenode(int x, Treenode* left, Treenode* right): val(x), left(left),right(right) {}
};
class solution
{
public:
    // �������빹�������
    Treenode* creatTree(vector<int>& nums)
    {
        vector<Treenode*> vectree(nums.size(), NULL);
        Treenode* root = NULL;
        for (int i = 0; i < nums.size(); i++)
        {
            Treenode* node = NULL;
            if (nums[i] != -1)
            {
                node = new Treenode(nums[i]);
            }
            vectree[i] = node;
            if (i == 0) root = node;
        }
        for (int i = 0; i*2 +2 < nums.size(); i++)
        {
            if (vectree[i] != NULL)
            {
                vectree[i]->left = vectree[i * 2] + 1;
                vectree[i]->right = vectree[i * 2] + 2;
            }
        }
        return root;

    }
    // ����������ͺ����������һ��
    Treenode* creatTree(vector<int>& inOrder, vector<int>& postOrder)
    {
        if (postOrder.size() == 0) return NULL;
        int rootvalue = postOrder[postOrder.size() - 1];
        Treenode* root = new Treenode(rootvalue);
        if (postOrder.size() == 1) return root;
        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inOrder.size(); delimiterIndex++)
        {
            if (inOrder[delimiterIndex] == rootvalue) break;
        }
        // �Ѻ�����������һ��ȥ�������и�����
        vector<int> left_inOrder(inOrder.begin(), inOrder.begin() + delimiterIndex);
        vector<int> right_inOrder(inOrder.begin() + delimiterIndex + 1, inOrder.end());
        // ���������������Ҵ�С���жϺ�������Ļ���
        postOrder.resize(postOrder.size() - 1);
        vector<int> left_postOrder(postOrder.begin(), postOrder.begin() + left_inOrder.size());
        vector<int> right_postOrder(postOrder.begin() + left_inOrder.size(), postOrder.end());
        root->left = creatTree(left_inOrder, left_postOrder);
        root->right = creatTree(right_inOrder, right_postOrder);
        return root;
    }
    // ��߶ȣ����ú�������ĵݹ����ʵ��
    int getheight(Treenode* node)
    {
        if (node == NULL) return 0;
        int leftheight = getheight(node->left);
        if (leftheight == -1) return -1;
        int rightheight = getheight(node->right);
        if (rightheight == -1) return -1;
        return abs(leftheight - rightheight) > 1 ? -1 : max(leftheight, rightheight);
    }
    bool balanced_binary_tree(Treenode* root)
    {
        return getheight(root) == -1 ? false : true;
    }
};
int main()
{
    // ���������빹���������
    int number;
    vector<int> nums;
    while (cin>> number)
    {
        nums.push_back(number);
        if (cin.get() == '\n') break;

    }
    Treenode* root = solution().creatTree(nums);
    bool height = solution().balanced_binary_tree(root);
    cout << height << endl;
    return 0;
}