// 青蛙跳台阶、爬楼梯问题都是这种思路
// 剑指offer110，leetcode70
/*
（1）dp数组的含义就是爬上第i层楼梯有几种方式
（2）递推公式就是dp[i] = dp[i-1] + dp[i -2]
 (3) 初值是直接dp[1]给1，dp[2]給2，从3开始
 (4) 遍历顺序从前往后遍历即可
 (5) 自己递推验证
*/
#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    int climbingStairs(int n)
    {
        // 因为直接循环到n，所以大小为n+1
        //vector<int> dp(n + 1, 0);
        // 这种写法时间复杂度和空间复杂度都是O(N)
        int dp[3];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n ; i++)
        {
            //dp[i] = dp[i - 1] + dp[i - 2];
            // 优化一下空间复杂度
            int sum = dp[1] + dp[2];
            dp[1] = dp[2];
            dp[2] = sum;
        }
        return dp[2];
    }
};
int main()
{
    int n;
    cin >> n;
    int result = solution().climbingStairs(n);
    cout << result << endl;
    return 0;
}