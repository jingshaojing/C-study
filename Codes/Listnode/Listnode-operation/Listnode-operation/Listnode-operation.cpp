// 针对链表的常规操作
#include <iostream>
#include <vector>
using namespace std;
class myLinkedlist
{
public:
	struct Listnode
	{
		int val;
		Listnode* next;
		Listnode(int x) : val(x), next(NULL) {}
	};
	myLinkedlist()
	{
		_dummyhead = new Listnode(0);
		_size = 0;
	}
	// 获取第index个节点的值
	int getindex(int index)
	{
		if (index > (_size - 1) || index < 0)
		{
			return -1;
		}
		Listnode* cur = _dummyhead->next;
		while (index--)
		{
			cur = cur->next;
		}
		return cur->val;
	}
	// 在链表最前面插入一个节点，即把虚拟头结点指向插入的节点
	void addAthead(int val)
	{
		Listnode* newnode = new Listnode(val);
		newnode->next = _dummyhead->next;
		_dummyhead->next = newnode;
		_size++;
	}
	// 尾后添加
	void addAtTail(int val)
	{
		Listnode* newnode = new Listnode(val);
		Listnode* cur = _dummyhead;
		while (cur->next != nullptr)
		{
			cur = cur->next;
		}
		cur->next = newnode;
		_size++;
	}
	// 在第index个节点之前插入
	void addAtindex(int index, int val)
	{
		if (index > _size) return;
		Listnode* newnode = new Listnode(val);
		Listnode* cur = _dummyhead;
		while (index)
		{
			cur = cur->next;
		}
		newnode->next = cur->next;
		cur->next = newnode;
		_size++;
	}
	// 删除第index个节点
	void deleteAtindex(int index)
	{
		if (index >= _size || index < 0)
		{
			return;
		}
		Listnode* cur = _dummyhead;
		while (index--)
		{
			cur = cur->next;
		}
		Listnode* temp = cur->next;
		cur->next = cur->next->next;
		delete temp;
		_size--;
	}
	// 打印链表
	void printLinklist()
	{
		Listnode* cur = _dummyhead;
		while (cur->next != nullptr)
		{
			cout << cur->next->val << "->";
			cur = cur->next;
		}
		cout << endl;
	}
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
		cout << endl;
		return head;
	}
private:
	int _size;
	Listnode* _dummyhead;

};
int main()
{
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
	int n = nums.size();
	myLinkedlist Linkedlist = new myLinkedlist();
	myLinkedlist::Listnode* head = Linkedlist.creatListnode(nums, n);
	return 0;
}
