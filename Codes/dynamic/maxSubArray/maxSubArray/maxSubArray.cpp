// leetcode53,剑指offer42.本处采用动态规划的方法
#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int result = dp[0];
        for (int i = 1; i <nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > result) result = dp[i];
        }
        cout << result << endl;
        return result;

    }

};
int main()
{
    int numbers;
    vector<int> nums;
    while (cin >> numbers)
    {
        nums.push_back(numbers);
        if (cin.get() == '\n') break;
    }
    solution().maxSubArray(nums);
    return 0;

}