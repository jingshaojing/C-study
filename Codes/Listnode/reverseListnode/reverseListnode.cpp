// ��ת����Ȳ�������������һ������ͷ���ķ�ʽ
// ������һ���жϻ�������Ĺ���
// ��ת�������ת����������ȥ�ж��ǲ��ǻ���
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
        // ������Ҫcur->next,��Ȼ�ͺͺ���Ķ���
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
        Listnode* slow = head; // ��¼�м��λ��
        Listnode* fast = head;
        Listnode* prev = head; // ��ָ���ǰһ���ڵ������ָ�
        while (fast && fast ->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr; // �ָ�����
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
            // �ڸı�֮ǰ����cur->next;
            temp = cur->next;
            // cur->next�ı�ָ��
            cur->next = pre;
            // ����preΪ��ǰֵ
            pre = cur;
            // ����curΪ��һ��ֵ
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