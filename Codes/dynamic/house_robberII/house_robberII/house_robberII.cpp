// 打家劫舍2，因为形成环，还是不能偷相邻的，所以相当于把环展开，有一种偷法是从0开始到尾部元素前面一个结束
// 另外一种偷法是从1开始到尾部元素结束
// 动态规划的逻辑和打家劫舍1相同
#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    int house_robberII(vector<int>& nums, int start, int end)
    {
        vector<int> dp(nums.size());
        dp[0] = nums[start];
        dp[1] = max(start, start + 1);
        for (int i = start + 2; i <= end; i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i-1]);
        }
        return dp[end];
    }

};
int main()
{
    int number;
    vector<int> nums;
    while (cin >> number)
    {
        nums.push_back(number);
        if (cin.get() == '\n')
        {
            break;
        }
    }
    int result1 = solution().house_robberII(nums, 0, nums.size() - 2);
    int result2 = solution().house_robberII(nums, 1, nums.size() - 1);
    int result = max(result1, result2);
    cout << result << endl;
    return 0;

}