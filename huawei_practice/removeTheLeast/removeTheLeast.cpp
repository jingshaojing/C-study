#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class solution
{
public:
    string removeTheLeast(string& nums)
    {

        vector<int> temp(26, 0);
        int n = nums.length();
        for (int i = 0; i < n; i++)
        {
            temp[nums[i] - 'a']++;
        }
        int min = n + 1;
        for (int i = 0; i < 26; i++)
        {
            if (temp[i] != 0 && temp[i] < min)
            {
                min = temp[i];
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (temp[i] == min)
            {
                nums.erase(remove(nums.begin(), nums.end(), i + 'a'), nums.end());
            }
        }
        cout << nums << endl;
        return nums;
    }
};


int main()
{
    string s;
    while (cin >> s)
    {
        solution().removeTheLeast(s);
    }
    return 0;
}