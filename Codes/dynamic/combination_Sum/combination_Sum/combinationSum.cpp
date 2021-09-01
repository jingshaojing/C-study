// 组合总和，还是求解装满有几种方法的背包问题，因为元素可以无限取值
/*
(1) dp[i]表示装满容量为i的有几种方法
(2) 递推公式 dp[i] += dp[i-nums[j]
(3) 初始化 dp[0] = 1， 此处无实际物理意义
(4) 遍历顺序，因为这个地方求得排列，所以只能是先背包，后物品
(5) 举例推导验证
*/
#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    int combination_Sum(vector<int>& nums, int target)
    {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i - nums[j] >= 0 && dp[i] + dp[i - nums[j]] < INT_MAX)
                {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};
int main()
{
    int number;
    vector<int> nums;
    while (cin >> number)
    {
        nums.push_back(number);
        if (cin.get() == '\n') break;
    }
    int target;
    cin >> target;
    int result = solution().combination_Sum(nums, target);
    cout << result << endl;
    return 0;
}