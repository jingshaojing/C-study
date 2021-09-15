// 十大排序算法
#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
    // 快排
    // 找出一个基数，比基数大的放到右边，比基数小的放到左边，对左右区间递归执行该算法直到剩下一个数。
    // 不稳定的排序算法，空间复杂度O(logn),时间复杂度O(nlogn)
    // 不稳定性来源于如果出现相同数值的，会调换一次顺序，但原来是不必调换的
    void quickSort(vector<int>& nums, int start, int end)
    {
        if (start < end)
        {
            int l = start, r = end, pivot = nums[start];
            while (l < r)
            {
                // 从右向左寻找小于基准的
                while (l < r && nums[r] >= pivot) r--;
                nums[l] = nums[r];
                // 从左向右寻找大于基准的
                while (l < r && nums[l] < pivot) l++;
                nums[r] = nums[l];
            }
            nums[l] = pivot;
            quickSort(nums, start, l - 1);
            quickSort(nums, l + 1, end);

        }
    }
    // 冒泡排序
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
