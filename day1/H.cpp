#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
const int N = 3e5;
const ll MOD = 676767677;
int a[N];
vector<int> ids[N];
int main() {
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            ids[i].clear();
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            ids[a[i]].push_back(i);
        }
        if ((a[0] <= a[1] && a[0] != 0) || (a[n - 2] >= a[n - 1] && a[n - 1] != 0)) {
            cout << 0 << endl;
            continue;
        }
        bool flag = false;
        for (int i = 1; i < n - 1; i++) {
            if (a[i] != 0 && a[i] <= a[i - 1] && a[i] <= a[i + 1]) {
                cout << 0 << endl;
                flag = true;
                break;
            }
        }
        if (flag) {
            continue;
        }
        ll answ = 1;
        int cnt = ids[0].size(), prevcnt = 0;
        for (int i = 1; i < m; i++) {
            if (cnt == n) {
                break;
            }
            if (ids[i].size() == 0) {
                flag = true;
                break;
            }
            for (auto to : ids[i]) {
                if (to == 0) {
                    if (a[to] > a[to + 1] + 1) {
                        answ *= cnt - prevcnt;
                    } else {
                        answ *= cnt;
                    }
                } else if (to == n - 1) {
                    if (a[to] > a[to - 1] + 1) {
                        answ *= cnt - prevcnt;
                    } else {
                        answ *= cnt;
                    }
                } else {
                    if (a[to] > a[to - 1] + 1 || a[to] > a[to + 1] + 1) {
                        answ *= cnt - prevcnt;
                    } else {
                        answ *= cnt;
                    }
                }
                answ %= MOD;
            }
            prevcnt = cnt;
            cnt += ids[i].size();
        }
        if (flag) {
            cout << 0 << endl;
            continue;
        }
        cout << answ << endl;
    }
}
