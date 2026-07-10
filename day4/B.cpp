#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;
using ll = long long;

const ll N = 2e7 + 5, MOD = 1e9 + 7;
const ll INF = N * N;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k, mxid = 0;
        ll answ = 0;
        cin >> n >> k;
        for (int i = 0; i < k; i++) {
            cin >> a[i];
            if (a[i] > a[mxid]) {
                mxid = i;
            }
        }
        for (int i = 0; i < k; i++) {
            if (i == mxid) {
                continue;
            }
            answ += a[i] + a[i] - 1;
        }
        cout << answ << endl;
    }
}
