#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;
const int N = 2e6 + 5;

int zf[N];
int main() {
    string s1;
    cin >> s1;
    string revs = s1;
    reverse(revs.begin(), revs.end());
    string s = s1 + "#" + revs;
    int n = s.size();
    int l = 0, r = 0;
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
    int answ = 0;
    for (int len = 1; len <= s1.size(); len++) {
        int p = s1.size() + 1 + s1.size() - len;
        if (zf[p] >= len) {
            answ = len;
        }
    }
    cout << answ << endl;
}
