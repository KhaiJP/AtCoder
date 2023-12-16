#include<iostream>
#include<map>
#include<stack>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, K, k;
map<int, stack<int>> m;
bool is_1[200010], has_picked[200010], has_used[200010];

int main(){
  cin >> N;
  rep(i, 1, N+1){
    int t, x; cin >> t >> x;

    if(t == 1){
      m[x].push(i);
      is_1[i] = true;
    }

    if(t == 2){
      stack<int> &stk = m[x];
      if(stk.empty()){
        cout << -1 << endl;
        return 0;
      }
      int j = stk.top(); stk.pop();
      has_used[i] = true;
      has_picked[j] = true;
    }
  }

  rep(i, 1, N+1){
    if(has_picked[i]) ++k;
    if(has_used[i])   --k;
    K = max(K, k);
  }

  cout << K << endl;
  rep(i, 1, N+1)if(is_1[i]) cout << (has_picked[i] ? 1 : 0) << ' ';
  cout << endl;
  return 0;
}