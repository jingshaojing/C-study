// 华为购物车清单，没看懂
#include<iostream>
#include<vector>
using namespace std;
int main() {
    int M, N;
    cin >> M >> N;
    M /= 10;
    vector<vector<int>> price(N + 1, vector<int>(3, 0));
    vector<vector<int>> value(N + 1, vector<int>(3, 0));
    for (int i = 1; i <= N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c == 0) {
            price[i][0] = a / 10;
            value[i][0] = b;
        }
        else {
            if (price[c][1] != 0) {
                price[c][2] = a / 10;
                value[c][2] = b;
            }
            else {
                price[c][1] = a / 10;
                value[c][1] = b;
            }
        }
    }
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int a = price[i][0], b = value[i][0];
            int c = price[i][1], d = value[i][1];
            int e = price[i][2], f = value[i][2];
            dp[i][j] = j >= a ? max(dp[i - 1][j - a] + a * b, dp[i - 1][j]) : dp[i - 1][j];
            dp[i][j] = j >= a + c ? max(dp[i - 1][j - a - c] + a * b + c * d, dp[i][j]) : dp[i][j];
            dp[i][j] = j >= a + e ? max(dp[i - 1][j - a - e] + a * b + e * f, dp[i][j]) : dp[i][j];
            dp[i][j] = j >= a + c + e ? max(dp[i - 1][j - a - e - c] + a * b + c * d + e * f, dp[i][j]) : dp[i][j];
        }
    }
    cout << dp[N][M] * 10 << endl;
    return 0;
}