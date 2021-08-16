// 找出一个整数数组中的目标值,返回和等于目标值的元素下标
// 思路采用map记录
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> result;
        unordered_map<int, int> mapping;
        for (int i = 0; i < nums.size(); ++i)
        {
            mapping[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            const int gap = target - nums[i];
            if (mapping.find(gap) != mapping.end() && mapping[gap] > i)
            {
                result.push_back(i);
                result.push_back(mapping[gap]);
                break;
            }
        }
        cout << '[' << result[0] << "," << result[1] << ']' << endl;
        return result;
    }

};
int main()
{
    int numbers;
    int k;
    vector<int> nums;
    while (cin >> numbers)
    {
        nums.push_back(numbers);
        if (cin.get() == '\n')
        {
            break;
        }

    }
    cin >> k;
    // 测试输入是否正确,相当于上面输入是两行，碰到回车就转下一行
    for (auto& n : nums)
    {
        cout << n << endl;
    }
    cout << k << endl;
    // 
    solution().twoSum(nums, k);
    return 0;
}