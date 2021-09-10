// 翻转链表等操作，采用设置一个虚拟头结点的方式
// 再增加一个判断回文链表的功能
// 翻转链表可以转到数组里面去判断是不是回文
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
    bool isPanlinList(Listnode* head)
    {
        if (head == nullptr && head->next == nullptr)
        {
            return true;
        }
        Listnode* slow = head; // 记录中间的位置
        Listnode* fast = head;
        Listnode* prev = head; // 慢指针的前一个节点用来分割
        while (fast && fast ->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr; // 分割链表。
        Listnode* cur1 = head;
        Listnode* cur2 = reverseList(slow);
        while (cur1)
        {
            if (cur1->val != cur2->val) return false;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return true;

    }
    Listnode* reverseList(Listnode* head)
    {
        //Listnode* dummyHead = new Listnode(0);
        //dummyHead->next = head;
        //Listnode* cur = dummyHead;
        Listnode* pre = NULL, * temp;
        Listnode* cur = head;
        while (cur)
        {
            // 在改变之前保存cur->next;
            temp = cur->next;
            // cur->next改变指向
            cur->next = pre;
            // 更新pre为当前值
            pre = cur;
            // 更新cur为下一个值
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
    Listnode* l1 = creatListnode(num);
    bool result =  solution().isPanlinList(l1);
    //printfListnode(l2);
    cout << result << endl;
    return 0;
}