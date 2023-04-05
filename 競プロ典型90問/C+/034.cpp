#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, K;
int a[100010];

int main(){
  cin >> N >> K;
  rep(i, 0, N) cin >> a[i];

  // solve by two pointers（尺取り法）
  int l = 0, r = 0;
  // numbers in the substring in consideration
  multiset<int> S;
  // n_kinds : The kinds of numbers in S; S = {1,2,2,3,3,3} -> n_kinds = 3
  int ans = 0, n_kinds = 0;
  while(r < N){ // once r reach N, the subsequence cannot be longer
    auto itr = S.find(a[r]);

    if(n_kinds < K || itr != S.end()){
      S.insert(a[r]);
      ans = max(ans, (int)S.size());
      // increment n_kinds if a[r] is new <-> itr == S.end()
      n_kinds += itr == S.end();

      ++r;
    }else{
      S.erase(S.find(a[l]));
      // decrement n_kinds if no more a[l] in S
      n_kinds -= S.find(a[l]) == S.end();

      ++l;
    }
  }

  cout << ans << endl;
  return 0;
}