#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using P = pair<int, int>;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

P AB[300010];
int N, answer;
vector<int> ab[2];

// calculating length of Longest Increasing Subsequence(LIS, 最長増加部分列)
template<typename T>
T getLIS(vector<T> v){
  vector<T> dp;
  for(auto &a : v){
    auto itr = lower_bound(dp.begin(), dp.end(), a);
    if(itr == dp.end()) dp.push_back(a);
    else *itr = a;
  }

  return (T)dp.size();
}

int main(){
  cin >> N;
  rep(i, 0, N) cin >> AB[i].first;
  rep(i, 0, N) cin >> AB[i].second;
  sort(AB, AB+N);
  rep(i, 0, N) ab[0].push_back(AB[i].first);
  rep(i, 0, N) ab[1].push_back(AB[i].second);

  rep(i, 0, 2) answer += getLIS(ab[i]);
  cout << answer << endl;
}