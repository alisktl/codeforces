#include <iostream>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

    for(int t = 0; t < T; t++) {
        int N, M;
        cin >> N >> M;

        map<int, int> group_map;

        int number = 0;
        for(int i = 0; i < N; i++) {
            cin >> number;

            if(group_map.count(number%M) > 0) {
            	group_map[number%M] += 1;
            } else {
            	group_map[number%M] = 1;
            }
        }

        int count = 0;
        if(group_map.count(0) > 0) {
        	++count;
        }

        if(M%2 == 0) {
        	if(group_map.count(M/2) > 0) {
        		++count;
        	}
	    }

        for(int i = 1; i < (M + 1)/2; i++) {
        	if(group_map.count(i) > 0 && group_map.count(M - i) > 0) {
        		int count_1 = group_map[i];
        		int count_2 = group_map[M - i];

        		if(count_1 > count_2) {
        			count += (count_1 - count_2 - 1);
        		} else if(count_2 > count_1) {
        			count += (count_2 - count_1 - 1);
        		}
        		++count;
        	} else if(group_map.count(i) > 0) {
        		count += group_map[i];
        	} else if(group_map.count(M - i) > 0) {
        		count += group_map[M - i];
        	}
        }

        cout << count << "\n";
    }

	return 0;
}