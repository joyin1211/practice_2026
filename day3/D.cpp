#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

const int N = 105, MOD = 1e9 + 7;
ll dp[N][N], a[N][N];
bool unsafe[N][N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    dp[0][0] = a[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i < n && j < m) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[i + 1][j + 1]);
            }
            if (i < n) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[i + 1][j]);
            }
            if (j < m) {
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + a[i][j + 1]);
            }
        }
    }
    cout << dp[n][m] << '\n';
}
