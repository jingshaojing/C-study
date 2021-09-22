// leetcode131·Ö¸î»ØÎÄ´®
#include <iostream>
#include <vector>
#include <string>
using  namespace std;
class solution
{
    vector<vector<string>> result;
    vector<string> path;
public:
    vector<vector<string>> parition_palindrome(string s)
    {
        result.clear();
        path.clear();
        backtracking(s, 0);
        return result;

    }
private:
    void backtracking(const string& s, int startIndex)
    {
        if (startIndex > s.size())
        {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++)
        {
            if (ispalindrome(s, startIndex, i))
            {
                string temp = s.substr(startIndex, startIndex-i +1);
                path.push_back(temp);
            }
            else
            {

                continue;
            }
            backtracking(s, i + 1);
            path.pop_back();
        }

    }
    bool ispalindrome(const string& s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
};
int main()
{
    string s;
    cin >> s;
    vector<vector<string>> res = solution().parition_palindrome(s);
    for (auto ch : res)
    {
        for(auto c : ch)
        cout << c << endl;
    }
    return 0;


}