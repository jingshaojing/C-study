// 背包问题原始问题，所有动态规划中背包问题的来源
/*
(1) 确定dp数组为dp[i][j],表示把第i个物品放进容量为j的背包中所获得的最大价值
(2) 递推公式：如果当前物品的重量大于当前背包的体积，不放进去，则dp[i][j] = dp[i -1][j],
    如果当前背包的体积大于物品重量，则需要比较，首先就是在之前的价值 和 放完上一个以后剩下的体积加上当前这个物品的重量，这里就不用担心
    剩下的体积是否可以保证装进去，因为找到dp[i-1][j-weight[i]]就是找到预留当前空间大小的装上一个空间那么大的价值
(3) 初始化 首先体积为0的那一列全部为0，其次对于第一个物品，当背包体积大于第一个物品，就是第一个物品的价值
(4) 遍历顺序，先物品后背包
(5) 自己推导可以把矩阵都写一遍
*/
#include <iostream>
#include <vector>
using  namespace std;
class solution
{
public:
    int bagpackage(vector<int>& weight, vector<int>& value, int &max_weight)
    {
        /*
        int n = weight.size();
        vector<vector<int> > dp(n, vector<int>(max_weight + 1, 0));
        // 初始化
        for (int j = weight[0]; j <= max_weight; j++)
        {
            dp[0][j] = value[0];
        }
        // 根据遍历顺序递推
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= max_weight; j++)
            {
                if (j < weight[i])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
                }
            }
        }
        cout << dp[weight.size() - 1][max_weight] << endl;
        return dp[weight.size() - 1][max_weight];*/
        // 采用一维数组来进行动态规划
        // 初始化
        vector<int> dp(max_weight + 1, 0);
        // 递推公式，因为背包为了避免上一层值被覆盖，采用倒叙的方式来循环，所以不需要判断大小是否可以放入
        // dp[j] = max(dp[j], dp[j-weight[i]+value[i])
        // 遍历顺序，先物品后背包，背包采用倒叙的方式
        for (int i = 0; i < weight.size(); i++)
        {
            for (int j = max_weight; j >= weight[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
        cout << dp[max_weight] << endl;
        return dp[max_weight];


    }
};
int main()
{
    vector<int> weight = { 1,3,4 };
    vector<int> value = { 15,20,30 };
    int max_weight = 4;
    solution().bagpackage(weight, value, max_weight);
    return 0;
}