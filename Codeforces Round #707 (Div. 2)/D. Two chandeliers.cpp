#include <iostream>
#include <vector>
#include <unordered_map>
 
using namespace std;
 
long long gcd(long long a, long long b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}
 
long long lcm(long long a, long long b) {
    if(a < b) {
        long long temp = a;
        a = b;
        b = a;
    }
    return (a/gcd(a,b))*b;
}
 
void solve() {
    long long N, M;
    long long K;
 
    cin >> N >> M >> K;
 
    vector<long long> lights_N(N);
    vector<long long> lights_M(M);
 
    for(long long i = 0; i < N; i++) {
        cin >> lights_N[i];
    }
 
    for(long long i = 0; i < M; i++) {
        cin >> lights_M[i];
    }
 
    // swap vectors, so N <= M
    if(N > M) {
        long long temp = N;
        N = M;
        M = temp;
 
        vector<long long> temp_vect = lights_N;
        lights_N = lights_M;
        lights_M = temp_vect;
    }
 
    vector<long long> shifts(N);
    unordered_map<long long, long long> ids;
    for(long long i = 0; i < lights_N.size(); i++) {
        ids[lights_N[i]] = i;
        shifts[i] = M;
    }
 
    for(long long i = 0; i < lights_M.size(); i++) {
        if(ids.find(lights_M[i]) != ids.end()) {
            --shifts[((ids[lights_M[i]] - i)%N + N) % N];
        }
    }
 
    long long LCM = lcm(N, M);
 
    long long angry_day = 0;
    long long i = 0;
    long long K_STEP = 0, DAY_STEP = 0;
    for(i = 0; (i + M) % N != 0; i = (i + M) % N) {
        K_STEP += shifts[i];
        DAY_STEP += M;
    }
 
    K_STEP += shifts[i];
    DAY_STEP += M;
 
    if(K > K_STEP) {
        K -= K_STEP;
        angry_day += DAY_STEP;
    }
 
    for(long long step = 10000LL; step > 0; step-=1000) {
        for(long long i = 0; K > step*K_STEP; i++) {
            K -= step*K_STEP;
            angry_day += step*DAY_STEP;
        }
    }
 
    for(long long step = 1000LL; step > 0; step-=100) {
        for(long long i = 0; K > step*K_STEP; i++) {
            K -= step*K_STEP;
            angry_day += step*DAY_STEP;
        }
    }
 
    for(long long step = 100LL; step > 0; step-=10) {
        for(long long i = 0; K > step*K_STEP; i++) {
            K -= step*K_STEP;
            angry_day += step*DAY_STEP;
        }
    }
 
    for(long long i = 0; K > K_STEP; i++) {
        K -= K_STEP;
        angry_day += DAY_STEP;
    }
 
    for(long long i = 0; K > shifts[i]; i = (i + M) % N) {
        K -= shifts[i];
        angry_day += M;
    }
 
    for(long long i = 0; K > 0; i--) {
        if(lights_N[angry_day%N] != lights_M[angry_day%M]) K -= 1LL;
        angry_day += 1LL;
    }
 
    cout << angry_day << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    solve();
 
    return 0;
}