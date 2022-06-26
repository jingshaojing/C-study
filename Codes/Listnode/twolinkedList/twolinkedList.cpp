// 临时改成了美团的题，寻找出最长公共子串后，返回不同周期的个数。abcabcabc的话，前缀9长度的，周期还有6和3.
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class solution
{
public:
    int numberOfT(string& s, int u, int k)
    {
        int result = 0;
        int min_len = 0;
        //int step = 0;
        vector<int> temp;
        string temp_s = "";
        for (int i = 0; i < u; i++)
        {
            temp_s += s[i];
        }
        //if (!isString(temp_s))
        //{
            //temp.push_back(temp_s.size());
           // result = temp_s.size();
        //}
        //else
        //{
            for (int i = 0; i < temp.size(); i++)
            {
                if (s[i] == s[0])
                {
                    min_len = i;
                    break;
                }
                else
                {
                    min_len = temp.size();
                }
            }
            //step = u/min_len;
            for (int i = min_len; i <= u; i += min_len)
            {
                temp.push_back(i);
                //cout << i << endl;
            }
            result = temp[k - 1];
           // result = min_len;
        //}

        return result;
    }
    void getNext(vector<int> next, string& s)
    {
        next[0] = -1;
        int j = -1;
        for (int i = 1; i < s.size(); i++)
        {
            while (j >= 0 && s[i] != s[j + 1]) j = next[j];
            if (s[i] == s[j + 1]) j++;
            next[i] = j;
        }
        return;
    }
    bool isString(string s)
    {
        if (s.size() == 0) return false;
        vector<int> next(s.size());
        getNext(next, s);
        int len = s.size();
        if (next[len - 1] != -1 && (len - (next[len - 1] + 1)) == 0)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    string s;
    cin >> s;
    int number;
    cin >> number;
    //vector<vector<int> > data(number,vector<int>(2,0));
    int u, k, result;
    while (number--)
    {
        cin >> u >> k;
        result = solution().numberOfT(s, u, k);
        cout << result << endl;
    }
    return 0;
}