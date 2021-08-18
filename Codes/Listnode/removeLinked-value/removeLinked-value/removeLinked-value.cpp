// ����ͨ������ͷ��㷽�����
// leetcode203���Ƴ�����Ԫ�أ�ɾ�����ڸ���ֵ������ڵ�
#include <iostream>
#include <vector>
using namespace std;
struct Listnode
{
    int val;
    Listnode* next;
    // ��������幹�캯���Ļ���ʹ��Ĭ�Ϲ������ʱ���ܸ�������ʼ����ֵ
    Listnode(int x) : val(x),next(NULL) {}
};
void printListnode(Listnode* head);
class solution
{
public:
    Listnode* removeElements(Listnode* head, int value)
    {
        Listnode* dummyhead = new Listnode(0);
        dummyhead->next = head;
        Listnode* cur = dummyhead;
        while (cur->next != NULL)
        {
            if (cur->next->val == value)
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
        head = dummyhead->next;
        delete dummyhead;
        //printListnode(head);
        return head;
    }
};
// ��vectorԪ�ش�������
Listnode* creatListnode(vector<int> nums, int n)
{
    if (n == 0) return NULL;
    Listnode* head = new Listnode(nums[0]);
    Listnode* cur = head;
    cout << head->val << "->";
    for (int i = 1; i < n; i++)
    {
        cur->next = new Listnode(nums[i]);
        cout << cur->next->val << ">";
        cur = cur->next;
    }
    cout <<endl;
    return head;
}
// ��ӡ����
void printListnode(Listnode* head)
{
    Listnode* cur = head;
    cout << '[';
    while (cur != NULL)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << ']'<< endl;
    return;
}
int main()
{
    // vector��������
    int numbers, value;
    vector<int> nums;
    while (cin >> numbers)
    {
        nums.push_back(numbers);
        if (cin.get() == '\n')
        {
            break;
        }
    }
    cin >> value;
    int n = nums.size();
    Listnode* head = creatListnode(nums, n);
    head = solution().removeElements(head, value);
    printListnode(head);
    return 0;
}