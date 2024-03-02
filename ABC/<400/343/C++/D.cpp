#include<iostream>
#include<map>
using namespace std;
using ll = int64_t;

ll N, T, Score[200010];
map<ll, ll> kinds_counter;

int main(){
  cin >> N >> T;
  kinds_counter[0] = N;

  while(T--){
    ll A, B; cin >> A >> B;
    --kinds_counter[Score[A]];
    if(kinds_counter[Score[A]] == 0) kinds_counter.erase(Score[A]);

    Score[A] += B;
    ++kinds_counter[Score[A]];

    cout << kinds_counter.size() << endl;
  }

  return 0;
}