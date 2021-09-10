// 链表实现两数之和
#include <iostream>
#include <vector>
using namespace std;
struct Listnode
{
    int val;
    Listnode* next;
    Listnode() : val(0), next(nullptr){}
    Listnode(int x) : val(x), next(nullptr) {}
    Listnode(int x, Listnode *next) : val(x),next(next) {}

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
        // 这里写错了，需要cur->next,不然就和后面的断了
        cur->next = new Listnode(l[i]);
        cout << cur->val << " ";
        cur = cur->next;

    }
    cout << "]" << endl;
    return head;
}
void printfListnode(Listnode* head)
{
    Listnode* cur = head;
    while (cur != NULL )
    {
        cout << cur->val <<" ";
        cur = cur->next;
    }
    return;
}
class solution
{
public:
    Listnode* twoSumList(Listnode* l1, Listnode* l2)
    {
        Listnode dummy(-1);
        int carry = 0;
        Listnode* prev = &dummy;
        for (Listnode  *p1 = l1, *p2 = l2; 
            p1 != nullptr || p2 != nullptr; 
            p1 = p1 == nullptr? nullptr : p1 -> next, p2 = p2 == nullptr?nullptr:p2->next, prev = prev->next)
        {
            const int ai = p1 == nullptr ? 0 : p1->val;
            const int bi = p2 == nullptr ? 0 : p2->val;
            const int value = (ai + bi + carry) % 10;
            carry = (ai + bi + carry) / 10;
            prev->next = new Listnode(value);

        }
        if (carry > 0)
        {
            prev->next = new Listnode(carry);
        }
        return dummy.next;

    }
};
int main()
{
    vector<int> l1, l2;
    int number;
    while (cin >> number)
    {
        l1.push_back(number);
        if (cin.get() == '\n')
        {
            break;
        }
    }
    while (cin >> number)
    {
        l2.push_back(number);
        if (cin.get() == '\n')
        {
            break;
        }
    }
    Listnode* L1, * L2, * L3;
    L1 = creatListnode(l1);
    L2 = creatListnode(l2);
    //printfListnode(L1);
    L3 = solution().twoSumList(L1, L2);
    printfListnode(L3);
    return 0;

    
    
}