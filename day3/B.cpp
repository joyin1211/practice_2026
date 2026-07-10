#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

const int N = 3e6, MOD = 1e9 + 7;
ll dp[N];
int main() {
    int l, r;
    cin >> l >> r;
    dp[1] = 1;
    for (int i = 1; i <= r; i++) {
        if (dp[i] == 0) {
            continue;
        }
        for (int j = i + i; j <= r; j += i) {
            dp[j] = (dp[j] + dp[i]) % MOD;
        }
    }
    ll answ = 0;
    for (int i = l; i <= r; i++) {
        answ = (answ + dp[i]) % MOD;
    }
    cout << answ << endl;
}
