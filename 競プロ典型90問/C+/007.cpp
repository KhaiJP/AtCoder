#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int A[300010];

int main(){
  int N; cin >> N;
  rep(i, 0, N) cin >> A[i];
  sort(A, A+N);

  int Q; cin >> Q;
  while(Q){
    int b; cin >> b;
    auto itr = lower_bound(A, A+N, b);

    int ref1 = *itr;
    if(itr != A) --itr;
    int ref2 = *itr;
    
    cout << min(abs(b - ref1), abs(b - ref2)) << '\n';
    --Q;
  }
  
  cout << endl;
  return 0;
}