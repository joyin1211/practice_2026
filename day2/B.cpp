#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;


const int N = 2e6 + 6, M = 1e6 + 5;
int p[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        p[i] = j;
    }
    int per = n - p[n - 1];
    if (n % per == 0) {
        cout << per << '\n';
    } else {
        cout << n << '\n';
    }
}
