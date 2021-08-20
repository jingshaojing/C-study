#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    int maxSubmissions(vector<int>& nums)
    {
        int result = INT_MIN;
        int count = 0;
        for (int i = 0; i <nums.size(); i++)
        {
            count += nums[i];
            if (count > result) result = count;
            if (count < 0) count = 0;
        }
        cout << result << endl;
        return result;

    }

};
int main()
{
    int numbers;
    vector<int> nums;
    while (cin >> numbers)
    {
        nums.push_back(numbers);
        if (cin.get() == '\n') break;
    }
    solution().maxSubmissions(nums);
    return 0;
}