// 先判断是否有环
// 再判断环的入口
#include <iostream>
#include <vector>
using namespace std;
struct Listnode
{
    int val;
    Listnode* next;
    Listnode(int x) : val(x), next(NULL) {}
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
        cout << cur->val << " ";
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
    bool hascycle(Listnode* head)
    {
        if (head == nullptr || head->next == nullptr) return false;
        Listnode* slow = head;
        Listnode* fast = head->next;
        while (slow != fast)
        {
            if (fast == nullptr || fast->next == nullptr) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
    Listnode* detechCycle(Listnode* head)
    {
        Listnode* slow = head;
        Listnode* fast = head;
        while (fast != nullptr && fast->next != nullptr )
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                Listnode* index1 = fast;
                Listnode* index2 = slow;
                while (slow != fast)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;
            }
        }
        return NULL;
    }
};
int main()
{
    // 创建环形链表
}