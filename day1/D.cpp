#include <iostream>
#include <vector>
using namespace std;
const int N = 2e6;
vector<int> primes;
vector<bool> isPrime(N, true);
int main() {
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            for (int j = 2 * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    primes.push_back(1);
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> answ;
        answ.push_back(1);
        answ.push_back(2);
        for (int i = 2; i < n; i++) {
            answ.push_back(answ[i - 1] / primes[i - 2] * primes[i]);
        }
        for (auto to: answ) {
            cout << to << " ";
        }
        cout << endl;
    }
}
