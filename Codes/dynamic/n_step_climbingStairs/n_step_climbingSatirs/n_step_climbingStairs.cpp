// ǰ����¥�ݵ���Ŀ����ÿ����һ��¥�ݻ��������ף�����Ϊ��������¼�г��ļ���һ�ο�����m��
/*
(1) dp[i]���Ǳ�ʾ�����ڲ��м��ַ�ʽ
(2) ��ʼ��������m��ȷ����������Ҫ��0��ʼ����Ϊdp[0] = 1;
(3) ���ƹ�ʽ��������Ҫһ��˫��ѭ����������i�㣬��Ҫ�жϿ��Կ�Խ�Ĳ���j(1:m)û�г���Ŀǰ�Ľ�������ȻҲ����Ҫ����
(4) ����˳���Ǵ�ǰ����
(5) �Լ�����һ�飬����һ��������һ��������������¥�ݡ��ж����ַ�ʽ����n�㣬
*/
#include <iostream>
#include <vector>
using namespace std;
class solutioin
{
public:
    int n_step_climbingStairs(int n, int m)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i - j >= 0)
                {
                    dp[i] += dp[i - j];
                }
            }
        }
        return dp[n];
    }
};
int main()
{
    int number, m;
    cin >> number >> m;
    int result = solutioin().n_step_climbingStairs(number, m);
    cout << result << endl;
    return 0;
}