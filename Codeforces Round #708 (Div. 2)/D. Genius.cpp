#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
	int N;
	cin >> N;

	vector<int> points(N);
	vector<short> tags(N);
	vector<long long> total_points(N, 0);

	for(int i = 0; i < N; i++) cin >> tags[i];
	for(int i = 0; i < N; i++) cin >> points[i];

	for(int i = 1; i < N; i++) {
		for(int j = i-1; j >= 0; j--) {
			if(tags[i] == tags[j]) continue;

			long long total_points_i = total_points[i];
			long long total_points_j = total_points[j];

			int p = abs(points[i] - points[j]);

			total_points[i] = max(total_points_i, total_points_j + p);
			total_points[j] = max(total_points_j, total_points_i + p);
		}
	}

	cout << *max_element(total_points.begin(), total_points.end()) << "\n";
}

int main() {
    int T;
    cin >> T;

    while (T --> 0) {
        solve();
    }
    
    return 0;
}