// leetcode 第十一题——盛最多水的容器，可以视为接雨水的前奏。
#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
    int waterContainer_max(vector<int>& height)
    {
        int ans = 0;
        if (height.size() < 2)
        {
            return ans;
        }
        int i = 0;
        int j = height.size() - 1;
        while (i < j)
        {
            int area = (j - i) * min(height[i], height[j]);
            ans = max(ans, area);
            if (height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        cout << ans << endl;
        return ans;
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
    solution().waterContainer_max(nums);
    return 0;

}