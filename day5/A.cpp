#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
using ll = long long;
 
const int N = 200, MOD = 1e9 + 7;
const ll INF = 1e18;
ll a[N][N], dp[N][N];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> a[i][j];
            if (i == n - 1) {
                dp[i][j] = a[i][j];
            }
        }
        for (int j = i + 1; j < n; j++) {
            dp[i][j] = -INF;
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = a[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    cout << dp[0][0] << endl;
}
