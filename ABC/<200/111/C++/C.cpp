#include<iostream>
#include<map>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// m[j][number] = counts
// m[0][5] = 3 : 5 appears 3 times in even subsequence(j = 0)
map<int, int> m[2];

int main(){
  int n; cin >> n;

  rep(i, 0, n){
    int v; cin >> v;
    ++m[i&1][v];
  }

  // max_cnt[j]  : maximum counts that appear in even(odd) subsequence.
  // max2_cnt[j] : second maximum
  // max_num[j]  : the number that appears most in even(odd) subsequence.
  // max2_num[j] : the number that appears second most;
  int max_cnt[2] = {0, 0}, max2_cnt[2] = {0, 0};
  int max_num[2] = {0, 0}, max2_num[2] = {0, 0};

  rep(j, 0, 2){
    for(auto p : m[j]){
      const int &counts = p.second, &num = p.first;

      if(counts >= max_cnt[j]){
        max2_num[j] = max_num[j], max2_cnt[j] = max_cnt[j];
        max_num[j] = num, max_cnt[j] = counts;
      }
      else if(counts >= max2_cnt[j]){
        max2_num[j] = num, max2_cnt[j] = counts;
      }
    }
  }


  if(max_num[0] != max_num[1]){
    cout << n - (max_cnt[0] + max_cnt[1]) << endl;
  }else{
    int better = max(max_cnt[0] + max2_cnt[1], max2_cnt[0] + max_cnt[1]);
    cout << n - better << endl;
  }

  return 0;
}