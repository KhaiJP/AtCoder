#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

vector<ll> F[300010];
multiset<ll> most;
ll N, answer;

int main(){
  cin >> N;
  rep(i, 0, N){
    int f, s; cin >> f >> s; --f;
    F[f].push_back(s);
  }
  rep(i, 0, N) sort(F[i].rbegin(), F[i].rend());
  rep(i, 0, N) if(F[i].size()) most.insert(F[i][0]);

  if(most.size() == 1)rep(i, 0, N)if(F[i].size()){
    cout << F[i][0] + F[i][1]/2;
    return 0;
  }

  rep(i, 0, N)if(F[i].size()){
    ll tmp = F[i][0];
    most.erase(most.find(F[i][0]));
    tmp += *(most.rbegin());
    most.insert(F[i][0]);

    if(F[i].size() >= 2) tmp = max(tmp, F[i][0] + F[i][1]/2);
    answer = max(answer, tmp);
  }
  cout << answer << endl;
  return 0;
}