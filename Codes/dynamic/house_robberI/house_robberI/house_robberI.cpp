// leetcode 打家劫舍系列，动态规划
/*
(1) 数组含义，dp[i]表示投第i家的价值，如果不偷就和i-1一样，如果偷就是i-2,加上当前的
(2) 初始化，dp[0]就是nums[0],dp[1]则是nums[0]和nums[1]之间的最大值
(3) 递推公式 dp[i] = dp[i -2] + nums[i] ,i -1 是肯定不考虑的
(4) 遍历顺序，从前往后即可
(5) 自己手推验证
*/
#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    int house_robberI(vector<int>& nums)
    {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = dp[i - 2] + nums[i];
        }
        return dp[nums.size() - 1];
    }
};
int main()
{
    vector<int> nums;
    int number;
    while (cin >> number)
    {
        nums.push_back(number);
        if (cin.get() == '\n') break;
    }
    int result = solution().house_robberI(nums);
    cout << result << endl;
    return 0;
}