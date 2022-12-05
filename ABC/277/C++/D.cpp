#include<iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0; i<=n; ++i)
#define ll long long

using namespace std;

#ifndef ATCODER_DSU_HPP
#define ATCODER_DSU_HPP 1

#include <cassert>

namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

#endif  // ATCODER_DSU_HPP

using namespace atcoder;
int main(){
    int N, M; cin >> N >> M;
    vector<int> A(N);
    rep(i, N-1) cin >> A[i];
    sort(A.begin(), A.end());

    dsu uf(N);
    rep(i, N-1){
        int j = (i+1)%N;
        if(A[i]==A[j] || (A[i]+1)%M==A[j]){
            uf.merge(i, j);
        }
    }
    vector<ll> sum(N);
    rep(i, N-1) sum[uf.leader(i)] += A[i];
    ll mx = 0, total = 0;
    rep(i, N-1) mx = max(mx, sum[i]);
    rep(i, N-1) total += A[i];
    cout << total-mx << endl;
    return 0;
}
