// leetcode ��ҽ���ϵ�У���̬�滮
/*
(1) ���麬�壬dp[i]��ʾͶ��i�ҵļ�ֵ�������͵�ͺ�i-1һ�������͵����i-2,���ϵ�ǰ��
(2) ��ʼ����dp[0]����nums[0],dp[1]����nums[0]��nums[1]֮������ֵ
(3) ���ƹ�ʽ dp[i] = dp[i -2] + nums[i] ,i -1 �ǿ϶������ǵ�
(4) ����˳�򣬴�ǰ���󼴿�
(5) �Լ�������֤
*/
#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    int house_robberI(vector<int>& nums)
    {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = dp[i - 2] + nums[i];
        }
        return dp[nums.size() - 1];
    }
};
int main()
{
    vector<int> nums;
    int number;
    while (cin >> number)
    {
        nums.push_back(number);
        if (cin.get() == '\n') break;
    }
    int result = solution().house_robberI(nums);
    cout << result << endl;
    return 0;
}