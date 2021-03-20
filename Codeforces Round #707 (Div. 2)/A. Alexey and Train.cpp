#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<vector<int>> trips(N);
    vector<int> delay_time(N);

    int fact_leave_time = 0;
    int sch_leave_time = 0;

    for(int i = 0; i < N; i++) {
        trips[i] = vector<int>(2);
        cin >> trips[i][0];
        cin >> trips[i][1];
    }

    for(int i = 0; i < N; i++) {
        cin >> delay_time[i];
    }

    for(int i = 0; i < N; i++) {
        int trip_time = trips[i][0] - sch_leave_time + delay_time[i];
        int half_time = (int) ceil((trips[i][1] - trips[i][0])/2.0);

        if(i == N - 1) {
            cout << trip_time + fact_leave_time << "\n";
        }

        sch_leave_time = trips[i][1];
        fact_leave_time = trip_time + fact_leave_time + half_time> trips[i][1] ? trip_time + fact_leave_time + half_time : trips[i][1];
    }
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