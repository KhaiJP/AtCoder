#include<iostream>
#include<queue>
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

// first: -(T+W), second; -person_id
priority_queue<P> stash;
priority_queue<ll> in_line;
ll N, M, ate[200010];

int main(){
  cin >> N >> M;
  rep(i, 1, N+1) in_line.push(-i);
  // push dummy id not to make in_line empty
  in_line.push(-1e18);

  while(M--){
    ll T, W, S; cin >> T >> W >> S;

    // pull back guys from the stash
    while(stash.size()){
      ll schedule = -stash.top().first, person = stash.top().second;
      if(schedule > T) break;
      stash.pop();
      in_line.push(person);
    }
    // first person get noodle;
    ll person = in_line.top();
    if(person == -1e18) continue;
    ate[-person] += W;
    in_line.pop();
    stash.push({-(T + S), person});
  }

  rep(person, 1, N+1) cout << ate[person] << endl;
  return 0;
}
