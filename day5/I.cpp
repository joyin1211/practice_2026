#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
using ll = long long;
 
const int N = 505, MOD = 1e9 + 7;
const ll INF = 2e18;
ll a[N], p[N], dp[N * N];
int main() {
    ll n, w, sum_c = 0;
    cin >> n >> w;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> p[i];
        sum_c += p[i];
    }
    for (int i = 0; i <= sum_c; i++) {
        dp[i] = INF;
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = sum_c - p[i]; j >= 0; j--) {
            if (dp[j] + a[i] < dp[p[i] + j]) {
                dp[p[i] + j] = dp[j] + a[i];
            }
        }
    }
    ll answ = 0;
    for (int i = 0; i <= sum_c; i++) {
        if (dp[i] <= w) {
            answ = i;
        }
    }
    cout << answ << endl;
}
