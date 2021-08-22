#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 采用深度优先搜索
    vector<string> permutation(string s)
    {
        vector<string> res;
        int n = s.size();
        if (n == 0) return res;
        vector<int> visited(n, 0);
        string out = "";
        dfs(s, res, 0, visited, out);
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
    void dfs(string str, vector<string>& res, int level, vector<int>& visited, string& out)
    {

        int n = str.size();
        if (level == n)
        {
            res.push_back(out);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (i >= 1 && str[i] == str[i - 1] && visited[i - 1] == 0)
                continue;
            if (visited[i] == 1)
                continue;
            visited[i] = 1;
            out += str[i];
            dfs(str, res, level + 1, visited, out);
            out.pop_back();
            visited[i] = 0;
        }

    }
};
int main()
{
    string str;
    cin >> str;
    vector<string> result;
    result = Solution().permutation(str);
    for (auto ch : result) cout << ch << endl;
    return 0;
}