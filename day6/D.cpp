#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
using ll = long long;
 
const int N = 20, MOD = 1e9 + 7;
const ll INF = 2e18;

int a[N][N];
ll dp[1 << N][N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = 1;
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (dp[mask][i] == 0) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                if ((mask & (1 << j)) != 0) {
                    continue;
                }
                if (a[i][j]) {
                    dp[mask | (1 << j)][j] += dp[mask][i];
                }
            }
        }
    }
    ll answ = 0;
    for (int i = 0; i < n; i++) {
        answ += dp[(1 << n) - 1][i];
    }
    cout << answ << endl;
}
