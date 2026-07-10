#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

const int N = 1005, MOD = 1e9 + 7;
ll dp[N][N];
bool unsafe[N][N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        unsafe[x][y] = true;
    }
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (unsafe[i][j]) {
                continue;
            }
            if (i < n && !unsafe[i + 1][j]) {
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            }
            if (j < m && !unsafe[i][j + 1]) {
                dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
            }
        }
    }
    cout << dp[n][m] << '\n';
}
