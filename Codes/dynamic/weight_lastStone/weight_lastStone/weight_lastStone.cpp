// leetcode1049
// 对比上一道分割等和子集，这一题的思路也是依次给定dp[i]
// 上一题是判断是不是刚好装满，本题是判断最多可以装多少 sum-2*dp[target]
#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    int equal_subset(vector<int>& nums)
    {
        int sum = 0;
        for (auto& ch : nums)
        {
            sum += ch;
        }
        if (sum / 2 == 1) return false;
        int target = sum / 2;
        // 规定数组元素不超过30，且大小不超过1000，并全部初始为0.
        vector<int> dp(15001, 0);
        // 开始递推
        for (int i = 0; i < nums.size(); i++)
        {
            // 此处j肯定是到大于等于
            for (int j = target; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
                cout << dp[j] << " ";
            }
            cout << endl;
        }
        return sum - 2 * dp[target];

    }
};
int main()
{
    vector<int> nums;
    int number;
    while (cin >> number)
    {
        nums.push_back(number);
        if (cin.get() == '\n')
        {
            break;
        }
    }
    int result = solution().equal_subset(nums);
    cout << result << endl;
    return 0;
}