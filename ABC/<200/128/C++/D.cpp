#include<iostream>
#include<deque>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

deque<int> D;
int N, K, answer;

int solve(int l, int r){
  deque<int> d = D;
  // multiset of jewels taken from D
  multiset<int> S;
  rep(i, 0, l){
    int a = d.front();
    d.pop_front();
    S.insert(a);
  }
  rep(i, 0, r){
    int a = d.back();
    d.pop_back();
    S.insert(a);
  }
  // maximum number of jewels to insert to D 
  // insert as many negative valued jewels as possible
  int k = K - (l + r);
  while(S.size() && k){
    int a = *S.begin();
    if(a > 0) break;
    S.erase(S.begin());
    --k;
  }
  
  int result = 0;
  for(auto a : S) result += a;
  return result;
}

int main(){
  cin >> N >> K;
  rep(i, 0, N){
    int v; cin >> v;
    D.push_back(v);
  }

  // l(r) is the number of jewels taken from the left(right)
  rep(l, 0, N+1)rep(r, 0, N+1)if(l + r <= N && l + r <= K){
    answer = max(answer, solve(l, r));
  }

  cout << answer << endl;
  return 0;
}