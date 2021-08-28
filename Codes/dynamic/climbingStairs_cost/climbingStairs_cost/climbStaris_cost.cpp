// leetcode 746,��С������¥��
// ����ѡ���0��ʼ���ߴ�1��ʼ��һ�ο���ѡ��������������һ�������ÿ�εĻ��Ѷ��ǱȽ�ǰ��������С�ļ��ϵ�ǰ¥�ݵģ�������һ��Ƚ�
/*
(1) dp[i] ��ʾ������i����Ҫ���ѵĴ���
(2) ��ʼ����Ϊ���Դ�0����1��ʼ����˾���0����1�Ĵ���
(3) ���ƹ�ʽ����ǰ��Ĵ���Ӧ����ǰ������Ƚ�С����һ��Ĵ��ۼ��ϵ�ǰ��һ���
(4) ����˳���ǰ�������
(5) �Լ�������֤����[10,15,20,40]Ϊ����Ӧ����15.
*/
#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    int climbingStairs_cost(vector<int>& costing)
    {
        int n = costing.size();
        vector<int> dp(n, 0);
        dp[0] = costing[0];
        dp[1] = costing[1];
        for (int i = 2; i < n; i++)
        {
            dp[i] = min(dp[i - 1], dp[i - 2]) + costing[i];
        }
        return min(dp[n - 1], dp[n - 2]);

    }
};
int main()
{
    vector<int> costing;
    int number;
    while (cin >> number)
    {
        costing.push_back(number);
        if (cin.get() == '\n') break;
    }
    int result = solution().climbingStairs_cost(costing);
    cout << result << endl;
    return 0;
}