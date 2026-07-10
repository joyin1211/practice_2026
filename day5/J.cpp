#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;
using ll = long long;

const ll N = 5e3 + 5, MOD = 1e9 + 7;
const ll INF = N * N;

ll dp[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int sm = n; sm >= i; sm--) {
            dp[sm] += dp[sm - i];
            dp[sm] %= MOD;
        }
    }
    cout << dp[n] << endl;
}
