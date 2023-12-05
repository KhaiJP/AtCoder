#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s) ; i < (t); ++i)

int cnt[510][510];

int main() {
    int N, M, Q; cin >> N >> M >> Q;
    
    rep(i, 0, M) {
        int L, R; cin >> L >> R;
        cnt[L][R]++;
    }

    rep(L, 1, N+1)rep(R, 2, N+1) cnt[L][R] += cnt[L][R - 1];
    
    while(Q--){
        int p, q; cin >> p >> q;
        int answer = 0;
        rep(L, p, q + 1) answer += cnt[L][q];
        cout << answer << endl;
    }

    return 0;
}