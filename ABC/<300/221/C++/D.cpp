#include<iostream>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define MAX_N 200010

int ANS[MAX_N];
pair<ll, int> Event[2*MAX_N]; 

int main(){
  int N; cin >> N;
  rep(i,0,N){
    ll A, B; cin >> A >> B;
    Event[2*i  ] = {A,    1};
    Event[2*i+1] = {A+B, -1};
  }
  sort(Event, Event+2*N);

  int cnt = 0;
  rep(i,0,2*N-1){
    cnt += Event[i].second;
    ANS[cnt] += Event[i+1].first - Event[i].first;
  }

  rep(i,0,N) cout << ANS[i+1] << ' '; cout << endl;
  return 0;
}
