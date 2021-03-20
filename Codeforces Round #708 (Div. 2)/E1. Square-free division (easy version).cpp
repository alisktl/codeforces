#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAX_N = 1e7;

int min_factors[MAX_N + 1];
vector<int> primes;

void set_min_factors() {
    for(int i = 2; i <= MAX_N; i++) {
        if(min_factors[i] == 0) {
            min_factors[i] = i;
            primes.emplace_back(i);
        }

        for(int p : primes) {
            if(p > min_factors[i] || p*i > MAX_N) break;
            min_factors[p*i] = p;
        }
    }
}

void solve() {
    int N, K;
    cin >> N >> K;

    vector<int> masks(N);

    for(int i = 0; i < N; i++) {
        int x, p, last, count = 0, mask = 1;
        cin >> x;

        while(x > 1) {
            p = min_factors[x];

            if(last == p) {
                ++count;
            } else {
                if(last != 0) {
                    if(count % 2 == 1) {
                        mask *= last;
                    }
                }

                count = 1;
                last = p;
            }

            x /= p;
        }

        if(count % 2 == 1) {
            mask *= last;
        }

        masks[i] = mask;
    }

    map<int, map<int, int>> mask_count_map;
    int max_mask_count = 1;
    for(int i = 0; i < N; i++) {
        if(mask_count_map[max_mask_count].count(masks[i]) > 0) {
            ++max_mask_count;
        }

        mask_count_map[max_mask_count][masks[i]] = i;
    }

    cout << max_mask_count << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    set_min_factors();

    int T;
    cin >> T;

    while(T --> 0) {
        solve();
    }

    return 0;
}
