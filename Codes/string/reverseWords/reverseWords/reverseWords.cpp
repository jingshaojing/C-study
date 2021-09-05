// 翻转字符串中的单词
// 不只是单独翻转，还需要去除首尾多余的空格
// 思路先翻转整个字符串，然后去除首尾的空格，之前根据碰到空格就翻转区间内，就得到单词
#include <iostream>
#include <string>
using namespace std;
class solution
{
public:
    // 实现一个翻转左闭右闭的reverse
    void reverse(string& s, int start, int end)
    {
        for ( int i = start, j =end; i < j; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }
    void removeExtraSpace(string& s)
    {
        int slow = 0, fast = 0;
        // 移除开头的
        while (s.size() > 0 && fast < s.size() && s[fast] == ' ')
        {
            fast++;
        }
        // 移除中间的，相当于把所有的都集中到s[slow],跳过中间多余空格，当然中间的一个空格也被复制到s[slow]
        for (; fast < s.size(); fast++)
        {
            if (fast - 1 > 0 && s[fast - 1] == s[fast] && s[fast] == ' ')
            {
                continue;
            }
            else
            {
                s[slow++] = s[fast];
            }
        }
        // 移除末尾的
        if (slow - 1 > 0 && s[slow - 1] == ' ')
        {
            s.resize(slow - 1);
        }
        else
        {
            s.resize(slow);
        }
    }
    string reverseWords(string& s)
    {
        removeExtraSpace(s);
        reverse(s, 0, s.size() - 1);
        for (int i = 0; i < s.size(); i++)
        {
            int j = i;
            while (j < s.size() && s[j] != ' ')
            {
                j++;
            }
            reverse(s, i, j - 1);
            i = j;
        }
        return s;

    }
};
int main()
{
    string s;
    getline(cin, s);
    string result;
    result = solution().reverseWords(s);
    cout << result << endl;
}