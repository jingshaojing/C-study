// leetcode1049
// �Ա���һ���ָ�Ⱥ��Ӽ�����һ���˼·Ҳ�����θ���dp[i]
// ��һ�����ж��ǲ��Ǹպ�װ�����������ж�������װ���� sum-2*dp[target]
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
        // �涨����Ԫ�ز�����30���Ҵ�С������1000����ȫ����ʼΪ0.
        vector<int> dp(15001, 0);
        // ��ʼ����
        for (int i = 0; i < nums.size(); i++)
        {
            // �˴�j�϶��ǵ����ڵ���
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