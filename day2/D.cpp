#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <unordered_set>

using namespace std;
using ll = long long;
const int N = 1e4 + 5, MOD = 1e9 + 7, P = 37;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    ll answ = 0;
    string cur = "";
    for (int j = 0; j < n; j++) {
        cur += s[j];
        int len = cur.size();
        string rs = cur;
        reverse(rs.begin(), rs.end());
        string ns = rs;
        int m = ns.size();
        vector<int> zf(m, 0);
        int l = 0, r = 0;
        int zmax = 0;
        for (int i = 1; i < m; i++) {
            if (i <= r){
                zf[i] = min(r - i + 1, zf[i - l]);
            }
            while (i + zf[i] < m && ns[zf[i]] == ns[i + zf[i]]) {
                zf[i]++;
            }
            if (i + zf[i] - 1 > r) {
                l = i;
                r = i + zf[i] - 1;
            }
        }
        for (int i = 0; i < m; i++) {
            zmax = max(zmax, zf[i]);
        }
        answ += len - zmax;
    }
    cout << answ << '\n';
}
