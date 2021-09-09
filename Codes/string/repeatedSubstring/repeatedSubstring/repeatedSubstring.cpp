#include <iostream>
#include <string>
#include <vector>
using namespace std;
class solution
{
public:
    void getNext(vector<int> &Next, string& s)
    {
        int j = -1;
        Next[0] = -1;
        for (int i = 1; i < s.size(); i++)
        {
            while (j >= 0 && s[i] != s[j + 1])
            {
                j = Next[j];
            }
            if (s[i] == s[j + 1])
            {
                j++;
            }
            Next[i] = j;
        }
        return;
    }
    bool repeatedSubstring(string& s)
    {
        if (s.size() == 0) return false;
        vector<int> Next(s.size(),0);
        getNext(Next, s);
        int len = s.size();
        if (Next[len - 1] != -1 && len % (len - (Next[len - 1] + 1)) ==0)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    string s;
    getline(cin,s);
    bool result = solution().repeatedSubstring(s);
    cout << result << endl;
    return 0;
}