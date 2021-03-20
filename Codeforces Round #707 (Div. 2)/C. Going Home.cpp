#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

typedef pair<int, int> Pair;

void solve() {
    int N;
    cin >> N;

    vector<int> numbers(N);
    unordered_map<int, vector<int>> frequency_map;
    vector<int> size_of_two;

    for(int i = 0; i < N; i++){
        cin >> numbers[i];

        vector<int>& v = frequency_map[numbers[i]];

        v.emplace_back(i);

        if(v.size() >= 4) {
            cout << "YES" << "\n";
            cout << (v[0]+1) << ' ' << (v[1]+1) << ' ' << (v[2]+1) << ' ' << (v[3]+1) << "\n";
            return;
        }

        if(v.size() >= 2) {
            if(size_of_two.size() == 0) {
                size_of_two = v;
            } else {
                if(v[0] != size_of_two[0]) {
                    cout << "YES" << "\n";
                    cout << (size_of_two[0]+1) << ' ' << (v[0]+1)  << ' ' << (size_of_two[1]+1) << ' ' << (v[1]+1) << "\n";
                    return;
                }
            }
        }
    }

    unordered_map<int, vector<Pair>> sum_map;

    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            if(sum_map.count(numbers[i] + numbers[j])) {
                vector<Pair> pairs = sum_map[numbers[i] + numbers[j]];

                for(int k = 0; k < pairs.size(); k++) {
                    Pair _pair = pairs[k];

                    if((_pair.first != i && _pair.second != j) && (_pair.first != j && _pair.second != i)) {
                        cout << "YES" << "\n";
                        cout << (_pair.first+1) << ' ' << (_pair.second+1)  << ' ' << (i+1) << ' ' << (j+1) << "\n";
                        return;
                    }
                }
            }

            sum_map[numbers[i] + numbers[j]].emplace_back(Pair(i, j));
        }
    }

    cout << "NO" << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
