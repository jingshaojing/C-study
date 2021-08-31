// 分割等和子集，最关键的思想在于判断dp[j]=j,那么这就是等和子集
/*
（1） 确定dp数组含义，背包总容量是j，最大可以凑成的子集和为dp[j]
 (2)  递推公式 dp[j] = dp[j] + dp[i-weight[i]] + value[j], i是物品，此处还是先物品后背包
（3） 初始化，dp[0] = 0;
（4） 遍历顺序，物品外层，背包内层，内层倒叙
（5） 举例推导，如果dp[i] = i,那么就存在这样的子集。
*/
#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    bool equal_subset(vector<int>& nums)
    {
        int sum = 0;
        for (auto& ch : nums)
        {
            sum += ch;
        }
        if (sum / 2 == 1) return false;
        int target = sum / 2;
        // 规定数组元素不超过100，且大小不超过200，并全部初始为0.
        vector<int> dp(10001, 0);
        // 开始递推
        for (int i = 0; i < nums.size(); i++)
        {
            // 此处j肯定是到大于等于
            for (int j = target; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[target] == target)
        {
            cout << "true" << endl;
            return true;
        }
        return false;

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
    solution().equal_subset(nums);
    //cout << result << endl;
    return 0;
}