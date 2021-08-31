// ��ҽ���2����Ϊ�γɻ������ǲ���͵���ڵģ������൱�ڰѻ�չ������һ��͵���Ǵ�0��ʼ��β��Ԫ��ǰ��һ������
// ����һ��͵���Ǵ�1��ʼ��β��Ԫ�ؽ���
// ��̬�滮���߼��ʹ�ҽ���1��ͬ
#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    int house_robberII(vector<int>& nums, int start, int end)
    {
        vector<int> dp(nums.size());
        dp[0] = nums[start];
        dp[1] = max(start, start + 1);
        for (int i = start + 2; i <= end; i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i-1]);
        }
        return dp[end];
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
    int result1 = solution().house_robberII(nums, 0, nums.size() - 2);
    int result2 = solution().house_robberII(nums, 1, nums.size() - 1);
    int result = max(result1, result2);
    cout << result << endl;
    return 0;

}