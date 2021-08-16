// 给定数组判断其中和等于0的组合
// 三数之和返回的是值，所以可以使用双指针，但是两数之和题目不能使用双指针，因为使用双指针必须排序。排序之后顺序就发生了变化
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class solution
{
public:
    vector<vector<int> > threeSum(vector<int>& nums)
    {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            // 排序之后，如果第一个就大于0，肯定不存在
            if (nums[0] > 0) return result;
            // continue终止最近循环的当前循环，这种情况避免漏掉[-1,-1,2]的情况
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left)
            {
                if (nums[i] + nums[left] + nums[right] < 0) left++;
                else if (nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[left] + nums[right] == 0)
                {
                    result.push_back(vector<int> {nums[i], nums[left], nums[right]});
                    while (right > left && nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                    while (right > left && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    cout << nums[i] << "," << nums[left] << "," << nums[right] << endl;
                    left++;
                    right--;  
                   
                }              
            }
                     
        }
        return result;
    }
    
};
int main()
{
    int a = 0;
    vector<int> nums;
    while (cin >> a)
    {
        nums.push_back(a);
        if (cin.get() == '\n')
        {
            break;
        }
    }
    solution().threeSum(nums);
    return 0;
}