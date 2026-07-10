#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;
using ll = long long;

const ll N = 2e7 + 5, MOD = 1e9 + 7;
const ll INF = N * N;
ll dp[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        dp[i] = INF;
    }
    dp[1] = 0;
    for (int i = 1; i < n; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + i + 1);
        if (2 * i <= n) {
            dp[2 * i] = min(dp[2 * i], dp[i] + 2 * i);
        }
        if (3 * i <= n) {
            dp[3 * i] = min(dp[3 * i], dp[i] + 3 * i);
        }
    }
    cout << dp[n] << '\n';
}
