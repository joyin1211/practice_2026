#include <iostream>
using namespace std;
const int N = 3e5;
int a[N];
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for (int i = 1, j = 3 * n, ind = 0; i < j; i++, j -= 2, ind += 3) {
            a[ind] = i;
            a[ind + 1] = j;
            a[ind + 2] = j - 1;
        }
        for (int i = 0; i < 3 * n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}
