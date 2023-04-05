#include<iostream>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define rrep(i, s, t) for(int i = (s); i >= (t); --i)

const int INF = 1000000007;

struct LazySegTree{
  private:
    int N;
    vector<int> node, lazy;
    vector<bool> lazyFlag;
  
  public:
    LazySegTree(vector<int> v){
      int size = (int)v.size();
      N = 1; while(N < size) N *= 2;
      node.resize(2*N - 1);
      lazy.resize(2*N - 1, -INF);
      lazyFlag.resize(2*N - 1, false);

      rep(i, 0, size) node[i+N-1] = v[i];
      rep(i, N-2, 0) node[i] = max(node[2*i + 1], node[2*i + 2]);
    }

    void lazyEvaluate(int k, int l, int r){
      if(lazyFlag[k]){
        node[k] = lazy[k];
        if(r - l > 1){
          lazy[2*k + 1] = lazy[2*k + 2] = lazy[k];
          lazyFlag[2*k + 1] = lazyFlag[2*k + 2] = true;
        }
        lazyFlag[k] = false;
      }
    }

    void update(int a, int b, int x, int k=0, int l=0, int r=-1){
      if(r < 0) r = N;
      lazyEvaluate(k, l, r);
      if(b <= l || r <= a) return;
      if(a <= l && r <= b){
        lazy[k] = x;
        lazyFlag[k] = true;
        lazyEvaluate(k, l, r);
      }else{
        update(a, b, x, 2*k+1, l, (l+r)/2);
        update(a, b, x, 2*k+2, (l+r)/2, r);
        node[k] = max(node[2*k+1], node[2*k+2]);
      }
    }

    int find(int a, int b, int k=0, int l=0, int r=-1){
      if(r < 0) r = N;
      lazyEvaluate(k, l, r);
      if(b <= l || r <= a) return -INF;
      if(a <= l && r <= b) return node[k];
      int vl = find(a, b, 2*k+1, l, (l+r)/2);
      int vr = find(a, b, 2*k+2, (l+r)/2, r);
      return max(vl, vr);
    }
};


int main(){
  int W, N; cin >> W >> N;
  int a, b;
  LazySegTree seg(vector<int> (W+1, 0));

  rep(i, 0, N){
    int L, R; cin >> L >> R; --L;
    int num = seg.find(L, R) + 1;
    cout << num << '\n';
    seg.update(L, R, num);
  }

  cout << endl;
  return 0;
}