// 搜索旋转排序数组返回目标值的下标
#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    int searchArray(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        // middle必须定义在while里面，每次随着左右区间变化
        //int middle = (right - left) / 2;
        while (left != right)
        {
            int middle = left + (right - left) / 2;
            if (nums[middle] == target) { return middle; }
            if (nums[left] <= nums[middle])
            {
            if (nums[left] <= target && target <= nums[middle])  right = middle;
            else left = middle;
            }
            else
            {
                if (nums[middle] <= target && target << nums[right]) left = middle;
                else right = middle;
            }
        }
        return -1;
    }
};
int main()
{
    int target, numbers;
    vector<int> nums;
    while (cin >> numbers)
    {
        nums.push_back(numbers);
        if (cin.get() == '\n')
        {
            break;
        }
    }
    cin >> target;
    solution().searchArray(nums, target);
    return 0;

}