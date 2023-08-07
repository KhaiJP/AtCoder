#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define rrep(i, s, t) for(int i = (s); i >= (t); --i)

int C[11];

int main(){
  int N; cin >> N;
  rep(i, 1, 10) cin >> C[i];
  
  int mini = 1e9;
  rep(i, 1, 10) mini = min(mini, C[i]);

  // solved by greedya algo
  int remained_order = N / mini;
  while(remained_order--)rrep(i, 9, 1){
    int remained_budget  = N - C[i];
    if(remained_budget < 0) continue;
    int rem_order = remained_budget / mini;
    if(remained_order != rem_order) continue;

    cout << i;
    N -= C[i];
    break;
  }
  
  cout << endl;
  return 0;
}
