#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> result;
        if (nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        auto last = nums.end();
        for (auto a = nums.begin(); a < prev(last,3); a++)
        {
            for (auto b = next(a); b < prev(last, 2); b++)
            {
                auto c = next(b);
                auto d = prev(last);
                while (c < d)
                {
                    if (*a + *b + *c + *d < target) ++c;
                    else if (*a + *b + *c + *d > target) ++d;
                    else if (*a + *b + *c + *d == target)
                    {
                        result.push_back({ *a,*b,*c,*d });
                        ++c;
                        --d;
                        cout << "[" << *a << * b <<  * c << * d << "]" << endl;
                    }
                }
            }
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
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
    solution().fourSum(numbers, target);
    return 0;
}
