#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class solution
{
public:
    vector<int>  apro_threeSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int slow = 0, fast = 1;
        while (slow < fast && fast <= nums.size() -1)
        {
            if (nums[fast] != nums[slow])
            {
                
                nums[++slow] = nums[fast];
            }
            //slow++;
            fast++;
        }
        return nums;
        
    }
};
int main()
{
    vector<int> nums;
    int number;
    vector<int> result;
    while (cin >> number)
    {
        nums.push_back(number);
        if (cin.get() == '\n') break;
    }
    result = solution().apro_threeSum(nums);
    for (auto ch : result)
    {
        cout << ch << " ";
    }
    return 0;
}