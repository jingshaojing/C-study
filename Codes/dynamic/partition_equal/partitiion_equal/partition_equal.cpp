// �ָ�Ⱥ��Ӽ�����ؼ���˼�������ж�dp[j]=j,��ô����ǵȺ��Ӽ�
/*
��1�� ȷ��dp���麬�壬������������j�������Դճɵ��Ӽ���Ϊdp[j]
 (2)  ���ƹ�ʽ dp[j] = dp[j] + dp[i-weight[i]] + value[j], i����Ʒ���˴���������Ʒ�󱳰�
��3�� ��ʼ����dp[0] = 0;
��4�� ����˳����Ʒ��㣬�����ڲ㣬�ڲ㵹��
��5�� �����Ƶ������dp[i] = i,��ô�ʹ����������Ӽ���
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
        // �涨����Ԫ�ز�����100���Ҵ�С������200����ȫ����ʼΪ0.
        vector<int> dp(10001, 0);
        // ��ʼ����
        for (int i = 0; i < nums.size(); i++)
        {
            // �˴�j�϶��ǵ����ڵ���
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