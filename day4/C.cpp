#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;
using ll = long long;

const ll N = 2e6 + 5, MOD = 1e9 + 7;
const ll INF = N * N;
int a[N];
int dp[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> answ;
        for (int i = n; i >= k; i--) {
            answ.push_back(i);
        }
        for (int i = m + 1; i < k; i++) {
            answ.push_back(i);
        }
        for (int i = 1; i <= m; i++) {
            answ.push_back(i);
        }
        for (int i = 0; i < n; i++) {
            cout << answ[i] << " ";
        }
        cout << '\n';
    }
}
