// 前面爬楼梯的题目都是每次爬一阶楼梯或者爬两阶，本题为代码随想录中出的假如一次可以爬m阶
/*
(1) dp[i]还是表示爬到第层有几种方式
(2) 初始化，由于m不确定，所以需要从0开始，认为dp[0] = 1;
(3) 递推公式：这里需要一个双层循环，假如在i层，需要判断可以跨越的步数j(1:m)没有超过目前的阶数，不然也不需要跨了
(4) 遍历顺序还是从前往后
(5) 自己递推一遍，假设一步可以爬一个、两个、三个楼梯。有多少种方式到第n层，
*/
#include <iostream>
#include <vector>
using namespace std;
class solutioin
{
public:
    int n_step_climbingStairs(int n, int m)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i - j >= 0)
                {
                    dp[i] += dp[i - j];
                }
            }
        }
        return dp[n];
    }
};
int main()
{
    int number, m;
    cin >> number >> m;
    int result = solutioin().n_step_climbingStairs(number, m);
    cout << result << endl;
    return 0;
}