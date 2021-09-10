// 翻转链表等操作，采用设置一个虚拟头结点的方式
#include <iostream>
#include <vector>
using namespace std;
struct Listnode
{
    int val;
    Listnode* next;
    Listnode() : val(0), next(nullptr) {}
    Listnode(int x) : val(x), next(nullptr) {}
    Listnode(int x, Listnode* next) : val(x), next(next) {}
};
Listnode* creatListnode(vector<int>& l)
{
    if (l.size() == 0) return NULL;
    Listnode* head = new Listnode(l[0]);
    cout << " [";
    Listnode* cur = head;
    cout << cur->val << " ";
    for (int i = 1; i < l.size(); i++)
    {
        // 这里需要cur->next,不然就和后面的断了
        cur->next = new Listnode(l[i]);
        cout << cur-> next ->val << " ";
        cur = cur->next;

    }
    cout << "]" << endl;
    return head;
}
void printfListnode(Listnode* head)
{
    Listnode* cur = head;
    while (cur != NULL)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    return;
}
class solution
{
public:
    Listnode* reverseList(Listnode* head)
    {
        //Listnode* dummyHead = new Listnode(0);
        //dummyHead->next = head;
        //Listnode* cur = dummyHead;
        Listnode* pre = NULL, * temp;
        Listnode* cur = head;
        while (cur)
        {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};
int main()
{
    vector<int> num;
    int number;
    while (cin >> number)
    {
        num.push_back(number);
        if (cin.get() == '\n')
        {
            break;
        }
    }
    Listnode* l1 =creatListnode(num);
    Listnode* l2;
    l2 = solution().reverseList(l1);
    printfListnode(l2);
    return 0;
}