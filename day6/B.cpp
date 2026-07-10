#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
using ll = long long;
 
const int N = 20, MOD = 1e9 + 7;
const ll INF = 2e18;

int gr[N][N];
ll dp[1 << N][N];

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = INF;
        }
    }
    for (int i = 0; i < n; i++) {
        dp[1][i] = 0;
        for (int j = 0; j < n; j++) {
            cin >> gr[i][j];
        }
    }
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (((1 << i) & mask) == 0) {
                continue;
            }
            if (dp[mask][i] == INF) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (((1 << j) & mask) != 0) {
                    continue;
                }
                dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + gr[i][j]);
            }
        }
    }
    ll answ = INF;
    for (int i = 1; i < n; i++) {
        answ = min(answ, dp[(1 << n) - 1][i] + gr[i][0]);
    }
    cout << answ << endl;
}
