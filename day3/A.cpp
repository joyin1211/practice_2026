#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

const int N = 3e4, MOD = 1e9 + 7;
ll dp[N];
bool unsafe[N];
int main() {
    int n, k, m;
    ll sm = 1;
    cin >> n >> k >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        unsafe[x] = true;
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (i > k) {
            sm = (sm + MOD - dp[i - k - 1]) % MOD;
        }
        if (unsafe[i]) {
            dp[i] = 0;
            continue;
        }
        dp[i] = sm;
        sm += dp[i];
        sm %= MOD;
    }
    cout << dp[n] << endl;
}
