#include <iostream>

using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;

    K -= 3;;
    N -= K;

    for(int i = 0; i < K; i++) {
        cout << 1 << " ";
    }

    if(N == 3) {
        cout << 1 << " " << 1 << " " << 1 << "\n";
        return;
    }

    if(N & 1) {
        cout << 1 << " " << (N/2) << " " << (N/2) << "\n";
    } else if(N % 4 == 0) {
        cout << (N/2) << " " << (N/4) << " " << (N/4) << "\n";
    } else if(N % 2 == 0) {
        cout << 2 << " " << ((N - 2)/2) << " " << ((N - 2)/2) << "\n";
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

    for(int i = 0; i < T; i++) {
        solve();
    }

	return 0;
}