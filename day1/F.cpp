#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int N = 2e4;
vector<int> gr[N];
string s;
pair<int, int> bal[N];

void dfs(int v){
    for(auto to: gr[v]) {
        dfs(to);
        bal[v].first += bal[to].first;
        bal[v].second += bal[to].second;
    }
    if (s[v - 1] == 'W') {
        bal[v].first++;
    } else {
        bal[v].second++;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for (int i = 2; i <= n; i++) {
            int x;
            cin >> x;
            gr[x].push_back(i);
        }
        cin >> s;
        dfs(1);
        int answ = 0;
        for (int i = 1; i <= n; i++) {
            if (bal[i].first == bal[i].second) {
                answ++;
            }
        }
        cout << answ << endl;
        for (int i = 1; i <= n; i++) {
            gr[i].clear();
            bal[i] = {0, 0};
        }
    }
}
