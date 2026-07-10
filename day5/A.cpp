#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
using ll = long long;
 
const int N = 3e6, MOD = 1e9 + 7;
ll dp[N];
bool unsafe[N];
int main() {
    int n, k, m;
    ll sm = 1;
    cin >> n >> k;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (i > k) {
            sm = (sm + MOD - dp[i - k - 1]) % MOD;
        }
        dp[i] = sm;
        sm += dp[i];
        sm %= MOD;
    }
    cout << dp[n] << endl;
}
