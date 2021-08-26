// 斐波那契数列的动态规划
#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    // 动态规划
    /*int fabonacci(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }*/
    // 优化空间复杂度
    int fabonacci(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};
int main()
{
    int numbers, result;
    cin >> numbers;
    result = solution().fabonacci(numbers);
    cout << result << endl;
    return 0;
}