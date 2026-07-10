#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;
using ll = long long;

const ll N = 2e6 + 5, MOD = 1e9 + 7;
const ll INF = N * N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        bool flag = false;
        int used = 0;
        for (int i = 0; i < n + 1;) {
            if (i == 0 || i == n + 1 || (i >= 1 && s[i - 1] == 'L')) {
                bool jumped = false;
                for (int j = min(m, n - i + 1); j >= 1; j--) {
                    int nxt = i + j;
                    if (nxt == n + 1 || s[nxt - 1] == 'L') {
                        jumped = true;
                        i = nxt;
                        break;
                    }
                }
                if (!jumped) {
                    bool landed = false;
                    for (int j = min(m, n - i + 1); j >= 1; j--) {
                        int nxt = i + j;
                        if (nxt == n + 1) {
                            landed = true;
                            i = nxt;
                            break;
                        }
                        if (s[nxt - 1] == 'W') {
                            i = nxt;
                            landed = true;
                            break;
                        }
                    }
                    if (!landed) {
                        flag = true;
                        break;
                    }
                }
            } else {
                if (i == n) {
                    used++;
                    i = n + 1;
                    if (used > k) {
                        flag = true;
                        break;
                    }
                } else {
                    int nxt = i + 1;
                    if (s[nxt - 1] == 'C') {
                        flag = true;
                        break;
                    }
                    used++;
                    if (used > k) {
                        flag = true;
                        break;
                    }
                    i = nxt;
                }
            }
        }
        if (flag) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }
}
