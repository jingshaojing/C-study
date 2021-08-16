#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // ¶¯Ì¬¹æ»®
    int cuttingRope(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; ++i)
        {
            for (int j = 1; j <= i - 1; j++)
            {
                cout << dp[i] << " " << j << " " << j * (i - j) << " " << dp[i - j] << endl;
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
                cout << dp[i] << endl;
            }
        }
        cout << dp[n] << endl;
        return dp[n];
    }
};
int main()
{
    int numbers;
    cin >> numbers;
    Solution().cuttingRope(numbers);
    return 0;
}