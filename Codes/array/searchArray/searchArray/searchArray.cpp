// ������ת�������鷵��Ŀ��ֵ���±�
#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    int searchArray(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        // middle���붨����while���棬ÿ��������������仯
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