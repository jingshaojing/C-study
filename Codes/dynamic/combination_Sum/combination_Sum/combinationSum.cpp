// ����ܺͣ��������װ���м��ַ����ı������⣬��ΪԪ�ؿ�������ȡֵ
/*
(1) dp[i]��ʾװ������Ϊi���м��ַ���
(2) ���ƹ�ʽ dp[i] += dp[i-nums[j]
(3) ��ʼ�� dp[0] = 1�� �˴���ʵ����������
(4) ����˳����Ϊ����ط�������У�����ֻ�����ȱ���������Ʒ
(5) �����Ƶ���֤
*/
#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    int combination_Sum(vector<int>& nums, int target)
    {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i - nums[j] >= 0 && dp[i] + dp[i - nums[j]] < INT_MAX)
                {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};
int main()
{
    int number;
    vector<int> nums;
    while (cin >> number)
    {
        nums.push_back(number);
        if (cin.get() == '\n') break;
    }
    int target;
    cin >> target;
    int result = solution().combination_Sum(nums, target);
    cout << result << endl;
    return 0;
}