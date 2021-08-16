// 有序数组原地删除
#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    /*  这是使得每个元素最多出现一次版本，只返回修改后的长度*/
    /*
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.empty()) return 0;
        int index = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[index] != nums[i])
            {
                nums[++index] = nums[i];
            }
        }
        cout << index << endl;
        return index + 1;
    }*/
    int removeDuplicates2(vector<int> nums)
    {
        if (nums.size() < 3) return nums.size();
        int index = 2;
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i] != nums[index - 2])
            {
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};
int main()
{
    int numbers;
    vector<int> nums;
    while (cin >>numbers)
    {
        nums.push_back(numbers);
        if (cin.get() == '\n') break;
    }
    solution().removeDuplicates2(nums);
    return 0;
}