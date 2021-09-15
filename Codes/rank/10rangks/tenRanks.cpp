// ʮ�������㷨
#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
    // ����
    // �ҳ�һ���������Ȼ�����ķŵ��ұߣ��Ȼ���С�ķŵ���ߣ�����������ݹ�ִ�и��㷨ֱ��ʣ��һ������
    // ���ȶ��������㷨���ռ临�Ӷ�O(logn),ʱ�临�Ӷ�O(nlogn)
    // ���ȶ�����Դ�����������ͬ��ֵ�ģ������һ��˳�򣬵�ԭ���ǲ��ص�����
    void quickSort(vector<int>& nums, int start, int end)
    {
        if (start < end)
        {
            int l = start, r = end, pivot = nums[start];
            while (l < r)
            {
                // ��������Ѱ��С�ڻ�׼��
                while (l < r && nums[r] >= pivot) r--;
                nums[l] = nums[r];
                // ��������Ѱ�Ҵ��ڻ�׼��
                while (l < r && nums[l] < pivot) l++;
                nums[r] = nums[l];
            }
            nums[l] = pivot;
            quickSort(nums, start, l - 1);
            quickSort(nums, l + 1, end);

        }
    }
    // ð������
    void bubbleSort(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 0) return;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1 - i; j++)
            {
                if (nums[j] > nums[j + 1])
                {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
        return;
    }
};
int main()
{
    int number;
    vector<int> num;
    while (cin>> number)
    {
        num.push_back(number);
        if (cin.get() == '\n')
        {
            break;
        }
    }
    //solution().bubbleSort(num);
    solution().quickSort(num, 0, num.size() - 1);
    for (auto ch : num)
    {
        cout << ch << " ";
    }
    return 0;
}
