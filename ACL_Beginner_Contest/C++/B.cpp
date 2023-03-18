#include<iostream>
#include<algorithm>
using namespace std;
using ll = int64_t;

pair<ll, ll> range[2];

int main(){
  cin >> range[0].first >> range[0].second >> range[1].first >> range[1].second;
  sort(range, range + 2);
  cout << ( range[1].first <= range[0].second ? "Yes" : "No" ) << endl;
  return 0;
}