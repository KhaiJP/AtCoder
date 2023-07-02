#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

string cityIDs[100010];

string generate_ID(int p, int x){
  string tmp = to_string(p);
  string y = ""; rep(i, 0, 6-tmp.size()) y += '0'; y += tmp;
  tmp = to_string(x);
  string s = ""; rep(i, 0, 6-tmp.size()) s += '0'; s += tmp;
  return y + s;
}

int main(){
  int N, M; cin >> N >> M;
  map<int, vector<pair<int,int> > > pref_to_cities;

  rep(i, 0, M){
    int P, Y; cin >> P >> Y;
    pref_to_cities[P].push_back({Y,i});
  }

  for(auto &p : pref_to_cities) sort(p.second.begin(), p.second.end());

  for(auto p : pref_to_cities){
    int pref = p.first;
    auto v = p.second;
    rep(i, 0, v.size()) cityIDs[v[i].second] = generate_ID(pref, i+1);
  }

  rep(i, 0, M) cout << cityIDs[i] << endl;
  return 0;
}