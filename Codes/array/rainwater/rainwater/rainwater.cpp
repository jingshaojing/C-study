// ����ˮ leetcode42�� ���ʢ���ˮ��������˼·����������߱Ƚϵ͵�Ϊ��
// ˫ָ���ѶȽϴ�,����Ϊ������ֻҪ����ÿһ�ж�Ӧ�ĸ߶�
#include <iostream>
#include <vector>
using  namespace std;
class solution
{
public:
    int rainwater_max(vector<int>& height)
    {
        int sum = 0;
        for (int i = 0; i < height.size(); i++)
        {
            if (i == 0 || i == height.size()) continue;
            int lheight = height[i];
            int rheight = height[i];
            // �ұ���ߵĸ߶ȸ�����ǰֵ
            for (int r = i + 1; r < height.size(); r++)
            {
                if (height[r] > rheight) rheight = height[r];
            }
            // �����ߵĸ߶ȸ�����ǰֵ
            for (int l = i - 1; l > 0; l--)
            {
                if (height[l] > lheight) lheight = height[l];
            }
            int h = min(lheight, rheight) - height[i];
            if (h > 0) sum += h;
        }
        cout << sum << endl;
        return sum;
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
    solution().rainwater_max(nums);
    return 0;
}