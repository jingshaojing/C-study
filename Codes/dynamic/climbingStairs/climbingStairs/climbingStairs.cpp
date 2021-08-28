// ������̨�ס���¥�����ⶼ������˼·
// ��ָoffer110��leetcode70
/*
��1��dp����ĺ���������ϵ�i��¥���м��ַ�ʽ
��2�����ƹ�ʽ����dp[i] = dp[i-1] + dp[i -2]
 (3) ��ֵ��ֱ��dp[1]��1��dp[2]�o2����3��ʼ
 (4) ����˳���ǰ�����������
 (5) �Լ�������֤
*/
#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    int climbingStairs(int n)
    {
        // ��Ϊֱ��ѭ����n�����Դ�СΪn+1
        //vector<int> dp(n + 1, 0);
        // ����д��ʱ�临�ӶȺͿռ临�Ӷȶ���O(N)
        int dp[3];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n ; i++)
        {
            //dp[i] = dp[i - 1] + dp[i - 2];
            // �Ż�һ�¿ռ临�Ӷ�
            int sum = dp[1] + dp[2];
            dp[1] = dp[2];
            dp[2] = sum;
        }
        return dp[2];
    }
};
int main()
{
    int n;
    cin >> n;
    int result = solution().climbingStairs(n);
    cout << result << endl;
    return 0;
}