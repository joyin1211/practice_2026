#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
using ll = long long;


const int N = 24;

map<ll, ll> mp, real;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, c, d;
        cin >> n >> c >> d;
        mp.clear();
        real.clear();
        for (int i = 0; i < n * n; i++) {
            int x;
            cin >> x;
            mp[x]++;
        }
        int mn = (*mp.begin()).first;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ll x = mn + i * c + j * d;
                real[x]++;
            }
        }
        bool flag = false;
        for (auto to : real) {
            if (mp.find(to.first) == mp.end()) {
                flag = true;
                break;
            }
            if (mp[to.first] != to.second) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }
}
