#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
using ll = long long;
 
const int N = 200, MOD = 1e9 + 7;
const ll INF = 1e18;
ll a[N][N], dp[N][N];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = 0;
            }
        }
        for (int j = 1; j <= m; j++) {
            dp[0][j] = a[0][j - 1];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = dp[i - 1][j];
                for (int k = 0; k <= j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + a[i][k - 1]);
                }
            }
        }
        ll answ = dp[n - 1][m];
        cout << answ << endl;
    }
}
