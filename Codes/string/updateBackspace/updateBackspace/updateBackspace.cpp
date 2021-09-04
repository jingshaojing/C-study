// 剑指offer题目，替换字符串中的空格
// 主要思想是对空格计数，然后从后往前加
#include <iostream>
#include <string>
using namespace std;
class solution
{
public:
    string updateBackspace(string& str)
    {
        int oldsize = str.size();
        int count = 0;
        for (int i = 0; i < oldsize; i++)
        {
            if (str[i] == ' ')
            {
                count++;
            }
        }
        cout << count << endl;
        int newsize = oldsize + count * 2;
        str.resize(newsize);
        for (int i = newsize -1, j = oldsize -1; j < i; i--, j--)
        {
            if (str[j] != ' ')
            {
                str[i] = str[j];
            }
            else
            {
                str[i] = '0';
                str[i - 1] = '2';
                str[i - 2] = '%';
                i -= 2;
            }
            
        }
        return str;

    }
};
int main()
{
    string s;
    //string str;
    getline(cin, s);
    //while (cin >> s)
    //{
    //    str += s;
    //    if (cin.get() == '\n') break;
    //}
    //cout << s << endl;
    string result;
    result = solution().updateBackspace(s);
    cout << result << endl;
    return 0;
}