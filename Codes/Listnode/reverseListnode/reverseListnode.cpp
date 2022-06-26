// 翻转链表等操作，采用设置一个虚拟头结点的方式 (1)
// 再增加一个判断回文链表的功能
// 翻转链表可以转到数组里面去判断是不是回文(2)
// 增加删除链表指定值（3）
// 判断两个链表是否相交（4）
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
    Listnode* getInsertionNode(Listnode* head1, Listnode* head2)
    {
        // 返回链表相交的起始节点，否则返回NULL

    }
    Listnode* removeDuplicates(Listnode* head, int target)
    {
        // 删除需要定义虚拟头结点
        Listnode* dummy = new Listnode(0);
        dummy->next = head;
        Listnode* cur = dummy;
        // 这里必须是 cur->next != nullptr. 如果！cur->next会被认为是NULL，没有删除掉
        while (cur->next != nullptr)
        {
            if (cur->next->val == target)
            {
                Listnode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }
            else
            {
                cur = cur->next;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;

    }
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
    int target;
    cin >> target;
    Listnode* l1 = creatListnode(num);
    Listnode* l2 = solution().removeDuplicates(l1, target);
    //bool result =  solution().isPanlinList(l1);
    printfListnode(l2);
    //cout << result << endl;
    return 0;
}