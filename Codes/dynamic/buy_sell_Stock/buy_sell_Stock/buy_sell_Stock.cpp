// leetcode ��̬�滮 ���Ʊ
/*
(1) ȷ��dp���麬�壬dp[i][0]��ʾ���й�Ʊ�����棬dp[i][1]��ʾ�����й�Ʊ������
(2) ȷ�����ƹ�ʽ��dp[i][0]���й�Ʊ�Ŀ����ǵ������룬����Ļ�����-price[i],������Ļ�����dp[i-1][0]
dp[i][1]��ʾ�����й�Ʊ�����棬��������й�Ʊ������dp[i-1][1],������������ǽ���Ĺ�Ʊ�۸�price[i] + ǰһ����еĹ�Ʊ����dp[i][0]
(3) ��ʼ�� dp[0][0] ���ǵ�һ����й�Ʊ���������-price[0],dp[0][1]�����й�Ʊ����0
(4) ����˳�򣬴�ǰ����
*/
#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    int buy_sell_Stock(vector<int>& nums)
    {
        if (nums.size() == 0) return 0;
        vector<vector<int> > dp(nums.size(), vector<int>(2));
        // ��ʼ��
        dp[0][0] = -nums[0];
        dp[0][1] = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], -nums[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + nums[i]);
        }
        return dp[nums.size() - 1][1];

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
    int result = solution().buy_sell_Stock(nums);
    cout << result << endl;
}