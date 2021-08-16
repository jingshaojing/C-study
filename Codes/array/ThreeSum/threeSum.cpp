// ���������ж����к͵���0�����
// ����֮�ͷ��ص���ֵ�����Կ���ʹ��˫ָ�룬��������֮����Ŀ����ʹ��˫ָ�룬��Ϊʹ��˫ָ�������������֮��˳��ͷ����˱仯
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class solution
{
public:
    vector<vector<int> > threeSum(vector<int>& nums)
    {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            // ����֮�������һ���ʹ���0���϶�������
            if (nums[0] > 0) return result;
            // continue��ֹ���ѭ���ĵ�ǰѭ���������������©��[-1,-1,2]�����
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left)
            {
                if (nums[i] + nums[left] + nums[right] < 0) left++;
                else if (nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[left] + nums[right] == 0)
                {
                    result.push_back(vector<int> {nums[i], nums[left], nums[right]});
                    while (right > left && nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                    while (right > left && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    cout << nums[i] << "," << nums[left] << "," << nums[right] << endl;
                    left++;
                    right--;  
                   
                }              
            }
                     
        }
        return result;
    }
    
};
int main()
{
    int a = 0;
    vector<int> nums;
    while (cin >> a)
    {
        nums.push_back(a);
        if (cin.get() == '\n')
        {
            break;
        }
    }
    solution().threeSum(nums);
    return 0;
}