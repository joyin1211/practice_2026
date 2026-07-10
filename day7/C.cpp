#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
using ll = long long;


const int N = 2e5 + 5;
int a[N];

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        ll sm = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sm += a[i];
        }
        if (k >= sm) {
            cout << n << '\n';
            continue;
        }
        ll fk = k / 2 + k % 2;
        ll sk = k / 2;
        ll fkill = 0;
        ll skill = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > fk) {
                break;
            }
            fkill++;
            fk -= a[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] > sk) {
                break;
            }
            skill++;
            sk -= a[i];
        }
        cout << min(skill + fkill, n) << '\n';
    }
}
