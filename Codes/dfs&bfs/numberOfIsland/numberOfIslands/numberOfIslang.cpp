// 求岛屿数量，深度优先
// 在一个循环内上下左右搜，搜完一次加1.
#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    int numberOfIsland(vector<vector<char> >& grid)
    {
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(i, j, grid);
                    ++count;
                }
            }
        }
        return count;
    }
    void dfs(int row, int col, vector<vector<char> >& grid)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0')
        {
            return;
        }
        if (row > 0 && grid[row - 1][col] == '1') dfs(row - 1, col, grid);
        if (row > 0 && grid[row + 1][col] == '1') dfs(row + 1, col, grid);
        if (col > 0 && grid[row][col - 1] == '1') dfs(row, col - 1, grid);
        if (col > 0 && grid[row][col + 1] == '1') dfs(row, col + 1, grid);
        return;
    }
};
int main()
{
    char c;
    int m, n;
    cin >> m >> n;
    vector<vector<char> > grid(m, vector<char>(n, '0'));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    int result = solution().numberOfIsland(grid);
    cout << result << endl;
    return 0;
}