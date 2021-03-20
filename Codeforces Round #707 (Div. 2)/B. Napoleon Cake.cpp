#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<bool> result(N);
    vector<int> cream_unit(N);

    for(int i = 0; i < N; i++) {
        cin >> cream_unit[i];
    }

    int cream = 0;
    for(int i = N - 1; i >= 0; i--) {
        cream = max(cream, cream_unit[i]);
        if(cream > 0) result[i] = true;
        --cream;
    }

    for(int i = 0; i < N; i++) cout << result[i] << ' ';
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while(T --> 0) {
        solve();
    }
}