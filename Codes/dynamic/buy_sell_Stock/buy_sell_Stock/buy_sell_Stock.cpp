// leetcode 动态规划 买股票
/*
(1) 确定dp数组含义，dp[i][0]表示持有股票的收益，dp[i][1]表示不持有股票的收益
(2) 确定递推公式。dp[i][0]持有股票的可能是当天买入，买入的话就是-price[i],不买入的话就是dp[i-1][0]
dp[i][1]表示不持有股票的收益，如果不持有股票，就是dp[i-1][1],如果卖出，就是今天的股票价格price[i] + 前一天持有的股票数量dp[i][0]
(3) 初始化 dp[0][0] 就是第一天持有股票，收益就是-price[0],dp[0][1]不持有股票就是0
(4) 遍历顺序，从前往后
*/
#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    int buy_sell_Stock(vector<int>& nums)
    {
        if (nums.size() == 0) return 0;
        vector<vector<int> > dp(nums.size(), vector<int>(2));
        // 初始化
        dp[0][0] = -nums[0];
        dp[0][1] = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], -nums[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + nums[i]);
        }
        return dp[nums.size() - 1][1];

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
    int result = solution().buy_sell_Stock(nums);
    cout << result << endl;
}