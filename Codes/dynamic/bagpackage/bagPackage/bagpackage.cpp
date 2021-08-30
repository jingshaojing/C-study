// ��������ԭʼ���⣬���ж�̬�滮�б����������Դ
/*
(1) ȷ��dp����Ϊdp[i][j],��ʾ�ѵ�i����Ʒ�Ž�����Ϊj�ı���������õ�����ֵ
(2) ���ƹ�ʽ�������ǰ��Ʒ���������ڵ�ǰ��������������Ž�ȥ����dp[i][j] = dp[i -1][j],
    �����ǰ���������������Ʒ����������Ҫ�Ƚϣ����Ⱦ�����֮ǰ�ļ�ֵ �� ������һ���Ժ�ʣ�µ�������ϵ�ǰ�����Ʒ������������Ͳ��õ���
    ʣ�µ�����Ƿ���Ա�֤װ��ȥ����Ϊ�ҵ�dp[i-1][j-weight[i]]�����ҵ�Ԥ����ǰ�ռ��С��װ��һ���ռ���ô��ļ�ֵ
(3) ��ʼ�� �������Ϊ0����һ��ȫ��Ϊ0����ζ��ڵ�һ����Ʒ��������������ڵ�һ����Ʒ�����ǵ�һ����Ʒ�ļ�ֵ
(4) ����˳������Ʒ�󱳰�
(5) �Լ��Ƶ����԰Ѿ���дһ��
*/
#include <iostream>
#include <vector>
using  namespace std;
class solution
{
public:
    int bagpackage(vector<int>& weight, vector<int>& value, int &max_weight)
    {
        /*
        int n = weight.size();
        vector<vector<int> > dp(n, vector<int>(max_weight + 1, 0));
        // ��ʼ��
        for (int j = weight[0]; j <= max_weight; j++)
        {
            dp[0][j] = value[0];
        }
        // ���ݱ���˳�����
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= max_weight; j++)
            {
                if (j < weight[i])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
                }
            }
        }
        cout << dp[weight.size() - 1][max_weight] << endl;
        return dp[weight.size() - 1][max_weight];*/
        // ����һά���������ж�̬�滮
        // ��ʼ��
        vector<int> dp(max_weight + 1, 0);
        // ���ƹ�ʽ����Ϊ����Ϊ�˱�����һ��ֵ�����ǣ����õ���ķ�ʽ��ѭ�������Բ���Ҫ�жϴ�С�Ƿ���Է���
        // dp[j] = max(dp[j], dp[j-weight[i]+value[i])
        // ����˳������Ʒ�󱳰����������õ���ķ�ʽ
        for (int i = 0; i < weight.size(); i++)
        {
            for (int j = max_weight; j >= weight[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
        cout << dp[max_weight] << endl;
        return dp[max_weight];


    }
};
int main()
{
    vector<int> weight = { 1,3,4 };
    vector<int> value = { 15,20,30 };
    int max_weight = 4;
    solution().bagpackage(weight, value, max_weight);
    return 0;
}