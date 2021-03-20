#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> arr_1(N);
    
    for(int i = 0; i < N; i++) cin >> arr_1[i];

    sort(arr_1.begin(), arr_1.end());

    vector<int> arr_2;
    for(int i = 0; i < N; i++) {
        if(i == 0 || arr_1[i] != arr_1[i-1]){
            arr_2.emplace_back(arr_1[i]);
        }
    }

    for(int i = 1; i < N; i++) {
        if(arr_1[i] == arr_1[i-1]){
            arr_2.emplace_back(arr_1[i]);
        }
    }

    for(int i = 0; i < N; i++) cout << arr_2[i] << ' ';

    cout << "\n";
}

int main() {
    int T;
    cin >> T;

    while(T --> 0) {
        solve();
    }

    return 0;
}