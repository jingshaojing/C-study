// leetcode 746,最小花费爬楼梯
// 可以选择从0开始或者从1开始，一次可以选择爬两个或者爬一个，因此每次的花费都是比较前面两个较小的加上当前楼梯的，再与下一层比较
/*
(1) dp[i] 表示爬到第i层需要花费的代价
(2) 初始化因为可以从0或者1开始，因此就是0或者1的代价
(3) 递推公式：当前层的代价应该是前面两层比较小的那一层的代价加上当前这一层的
(4) 遍历顺序从前往后遍历
(5) 自己递推验证，以[10,15,20,40]为例，应该是15.
*/
#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    int climbingStairs_cost(vector<int>& costing)
    {
        int n = costing.size();
        vector<int> dp(n, 0);
        dp[0] = costing[0];
        dp[1] = costing[1];
        for (int i = 2; i < n; i++)
        {
            dp[i] = min(dp[i - 1], dp[i - 2]) + costing[i];
        }
        return min(dp[n - 1], dp[n - 2]);

    }
};
int main()
{
    vector<int> costing;
    int number;
    while (cin >> number)
    {
        costing.push_back(number);
        if (cin.get() == '\n') break;
    }
    int result = solution().climbingStairs_cost(costing);
    cout << result << endl;
    return 0;
}