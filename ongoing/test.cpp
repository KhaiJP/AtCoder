// #include <bits/stdc++.h>
#include<vector>
using namespace std;

void coordinate_compression(const vector<int> &vec, vector<int> &container);

int main(){
  vector<int> X{3, 22, 6, 8, 99, 1};
  vector<int> CC(X.size(), 0);
  coordinate_compression(X, CC);
  for(auto a: CC) cout << a << ' ';
  cout << endl;
  return 0;
}

void coordinate_compression(const vector<int> &vec, vector<int> &container){
  vector<int> tmp(vec.size());
  for (int i = 0; i < vec.size(); ++i) tmp[i] = vec[i];
  sort(tmp.begin(), tmp.end());

  tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
  for (int i = 0; i < vec.size(); ++i)
  {
    container[i] = lower_bound(tmp.begin(), tmp.end(), vec[i]) - tmp.begin();
    container[i] += 1;
  }
}