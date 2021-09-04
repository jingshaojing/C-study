// 组合问题，给定n，从1到n中找出k个数的组合
// 采用回溯的方法
#include <iostream>
#include <vector>
using namespace std;
class solution
{
private:
    vector<vector<int> > result;
    vector<int> path;
    void backtracking(int n, int k, int startIndex)
    {
        if (path.size() == k)
        {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n;  i++)
        {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combina(int n, int k)
    {
        result.clear();
        path.clear();
        backtracking(n, k, 1);
        return result;
    }
};
int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> result;
    result = solution().combina(n, k);
    cout << "[" << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < result[0].size(); j++)
        {
            if (j == result[0].size() - 1)
            {
                cout << result[i][j];
            }
            else
            {
                cout << result[i][j] << ",";
            }
            
        }
        cout << "]" << "," << endl;

    }
    cout << "]" << endl;
    return 0;
}