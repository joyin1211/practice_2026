#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int N = 2e6;
int zf[N];
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    string s = s2 + "#" + s1 + s1;
    int n = s.size();
    int l = 0, r = 0;
    if (s1.size() != s2.size()) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i < n; i++) {
        if (i <= r){
            zf[i] = min(r - i + 1, zf[i - l]);
        }
        while (i + zf[i] < n && s[zf[i]] == s[i + zf[i]]) {
            zf[i]++;
        }
        if (i + zf[i] - 1 > r) {
            l = i;
            r = i + zf[i] + 1;
        }
    }
    int ind = -1;
    for (int i = s2.size() + 1; i < n; i++) {
        if (zf[i] == s2.size()) {
            ind = i;
            break;
        }
    }
    if (ind == -1) {
        cout << -1 << endl;
        return 0;
    }
    cout << (s1.size() - ind + s2.size() + 1) % s1.size() << endl;
}
