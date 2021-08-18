// 接雨水 leetcode42， 相比盛最多水的容器，思路在于是以左边比较低的为主
// 双指针难度较大,以列为基础，只要计算每一列对应的高度
#include <iostream>
#include <vector>
using  namespace std;
class solution
{
public:
    int rainwater_max(vector<int>& height)
    {
        int sum = 0;
        for (int i = 0; i < height.size(); i++)
        {
            if (i == 0 || i == height.size()) continue;
            int lheight = height[i];
            int rheight = height[i];
            // 右边最高的高度给到当前值
            for (int r = i + 1; r < height.size(); r++)
            {
                if (height[r] > rheight) rheight = height[r];
            }
            // 左边最高的高度给到当前值
            for (int l = i - 1; l > 0; l--)
            {
                if (height[l] > lheight) lheight = height[l];
            }
            int h = min(lheight, rheight) - height[i];
            if (h > 0) sum += h;
        }
        cout << sum << endl;
        return sum;
    }
};
int main()
{
    int number;
    vector<int> nums;
    while (cin >> number)
    {
        nums.push_back(number);
        if (cin.get() == '\n')
        {
            break;
        }
    }
    solution().rainwater_max(nums);
    return 0;
}