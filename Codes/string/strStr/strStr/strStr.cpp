// 实现C语言strstr()函数，在第一个字符串中找出第二个字符串出现的位置
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class solution
{
public:
    void getNext(vector<int> &next, const string& s)
    {
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); i++)
        {
            while (j >= 0 && s[i] != s[j + 1])
            {
                j = next[j];
            }
            if (s[i] == s[j + 1])
            {
                j++;
            }
            next[i] = j;
        }
        return;
    }
    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0) return 0;
        // needle.size()并不是一个constexpr声明的函数；
        //constexpr int n = needle.size();
        //int next[needle.size()];
        vector<int> next(needle.size());
        getNext(next, needle);
        int j = -1;
        for (int i = 0; i < haystack.size(); i++)
        {
            while (j >= 0 && haystack[i] != needle[j+1])
            {
                j = next[j];
            }
            if (haystack[i] == needle[j + 1]) j++;
            if (j == (needle.size() - 1))
            {
                return i - needle.size() + 1;
            }

        }
        return -1;
    }
};
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int result = solution().strStr(s1, s2);
    cout << result << endl;
    return 0;
}