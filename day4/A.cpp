#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;
using ll = long long;

const ll N = 2e7 + 5, MOD = 1e9 + 7;
const ll INF = N * N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int k = 5;
        while(k--) {
            if (a <= b && a <= c) {
                a++;
                continue;
            }
            if (b <= a && b <= c) {
                b++;
                continue;
            }
            c++;
        }
        cout << a * b * c << endl;
    }
}
