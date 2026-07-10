#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;


const int N = 2e5 + 5, M = 1e6 + 5;
int a[N], b[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll n, m, k;
        cin >> n >> m >> k;
        vector<int> all;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            all.emplace_back(a[i]);
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
            all.emplace_back(b[i]);
        }
        sort(all.begin(), all.end());
        int sz = all.size();
        vector<int> cnt1(sz, 0), cnt2(sz, 0);
        for (int i = 0; i < m; i++) {
            int idx1 = lower_bound(all.begin(), all.end(), b[i]) - all.begin();
            int idx2 = lower_bound(all.begin(), all.end(), a[i]) - all.begin();
            cnt1[idx1]++;
            cnt2[idx2]++;
        }
        int answ = 0;
        int curcnt = 0;
        for (int i = 0; i < sz; i++){
            curcnt += min(cnt1[i], cnt2[i]);
        }
        if (curcnt >= k) {
            answ++;
        }
        for (int i = m; i < n; i++) {
            int idx = lower_bound(all.begin(), all.end(), a[i - m]) - all.begin();
            cnt2[idx]--;
            if (cnt2[idx] < cnt1[idx]) {
                curcnt--;
            }
            idx = lower_bound(all.begin(), all.end(), a[i]) - all.begin();
            cnt2[idx]++;
            if (cnt2[idx] <= cnt1[idx]) {
                curcnt++;
            }
            if (curcnt >= k) {
                answ++;
            }
        }
        cout << answ << '\n';
    }
}
