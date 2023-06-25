#include<iostream>
#include<deque>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  ll Q; cin >> Q;
  deque<int> S; S.push_back(1);

  mint answer = 1;
  rep(i, 0, Q){
    int e; cin >> e;

    if(e == 1){
      int x; cin >> x;
      S.push_back(x);
      answer = 10 * answer + x;
    }
    if(e == 2){
      answer -= mint(10).pow(S.size() - 1) * S.front();
      S.pop_front();
    }
    if(e == 3){
      cout << answer.val() << endl;
    }
  }

  return 0;
}