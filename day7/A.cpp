#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
using ll = long long;
 
const int N = 24;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;
        if (2 * a <= b) {
            cout << n * a << '\n';
        } else {
            cout << n / 2 * b + (n % 2) * a << '\n';
        }
    }
}
