#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class solution
{
public:
    int apro_threeSum(vector<int>& nums, int target)
    {
        int min_gap = INT_MAX;
        int result = 0;
        sort(nums.begin(), nums.end());
        for (auto a = nums.begin(); a != prev(nums.end(),2); a++)
        {
            auto b = next(a);
            auto c = prev(nums.end());
            while (b < c)
            {
                int sum = *a + *b + *c;
                int gap = abs(sum - target);
                if (gap < min_gap)
                {
                    min_gap = gap;
                    result = sum;
                }
                if (sum < target) ++b;
                else --c;

            }

        }
        cout << result << endl;
        return result;
    }
};
int main()
{
    vector<int> numbers;
    int target;
    int value;
    while (cin >> value)
    {
        numbers.push_back(value);
        if (cin.get() == '\n') break;
    }
    cin >> target;
    solution().apro_threeSum(numbers, target);
    return 0;
}