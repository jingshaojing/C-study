// 机器人的运动范围，不能进入各坐标数字之和
// 访问过的就设置flag为true，采用深度优先
// 坐标各数字之和超过18的不能进入
#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    int robotMoveRange(int m, int n, int k)
    {
        int count = 0;
        if (m < 1 || n < 1 || k < 1)
        {
            return count + 1;
        }
        //bool* visited = new bool[m * n];
        //memset(visited, 0, m * n);
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        count = dfs(m, n, k, 0, 0, visited);
        
        return count;
    }
    int getSum(int num)
    {
        int sum = 0;
        while (num)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    // 这里的viistied需要加引用&，不然例如3,2,17这种用例无法通过
    int dfs(int m, int n, int k, int rows, int cols, vector<vector<bool> > &visited)
    {
        int count = 0;
        if (rows >= 0 && rows < m && cols >= 0 && cols < n && getSum(rows) + getSum(cols) <= k && !visited[rows][cols])
        {
            visited[rows][cols] = true;
            count = 1 + dfs(m, n, k, rows + 1, cols, visited)
                + dfs(m, n, k, rows - 1, cols, visited)
                + dfs(m, n, k, rows, cols + 1, visited)
                + dfs(m, n, k, rows, cols - 1, visited);
        }
        return count;

    }
};
int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    int result = solution().robotMoveRange(m, n, k);
    cout << result << endl;
    return 0;
}