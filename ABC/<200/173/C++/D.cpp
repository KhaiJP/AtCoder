#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// kind of greedy algo
int main(){
  int N; cin >> N;
  vector<int> A(N);
  for(int i=0; i<N; ++i) cin >> A[i];
  sort(A.rbegin(), A.rend());
  int64_t answer = 0;
  for(int i=1; i<N; ++i){
    int id = i/2;
    answer += A[id];
  }
  cout << answer << endl;
  return 0;
}