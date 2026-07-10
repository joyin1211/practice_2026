#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
using ll = long long;
 
const int N = 24;

int a[N];
ll dp[1 << N];
int cnt[1 << N];

int main() {
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < (1 << n); i++) {
        int bit = __builtin_ctz(i);
        int prev = i ^ (1 << bit);
        dp[i] = dp[prev] ^ a[bit];
        cnt[i] = cnt[prev] + 1;
    }

    int answ = -1;
    for (int i = 0; i < (1 << n); i++) {
        if (cnt[i] == k) {
            if (dp[i] > answ) {
                answ = dp[i];
            }
        }
    }
    cout << answ << endl;
}
