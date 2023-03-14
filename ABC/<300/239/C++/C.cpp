#include<iostream>
#include<set>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define yes "Yes"
#define noo "No"

int main(){
  ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

  pair<ll, ll> ref[] = {{ 1,  2}, { 1, -2},
                        {-2,  1}, { 2,  1},
                        {-1, -2}, {-1,  2},
                        { 2, -1}, {-2, -1}};

  set<pair<ll, ll>> s1;
  rep(i, 0, 8) s1.insert({x1 + ref[i].first, y1 + ref[i].second});

  bool circle_there = false;
  rep(i, 0, 8){
    if( s1.count({x2 + ref[i].first, y2 + ref[i].second}) == 1 ){
      circle_there = true;
      break;
    }
  }

  cout << (circle_there ? yes : noo) << endl;
  return 0;
}