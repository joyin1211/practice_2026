#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--){
        int a[7], mxind = 0;
        for (int i = 0; i < 7; i++) {
            cin >> a[i];
            if (a[mxind] < a[i]) {
                mxind = i;
            }
        }
        int answ = 0;
        for (int i = 0; i < 7; i++) {
            if (i == mxind) {
                answ += a[i];
            } else {
                answ -= a[i];
            }
        }
        cout << answ << endl;
    }
}
