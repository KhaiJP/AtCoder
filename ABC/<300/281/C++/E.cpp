#include<iostream>
#include<set>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// U : Upper, bigger M-K numbers in A[i] ~ A[i+M-1]
// L : Lower, smaller K numbers in A[i] ~ A[i+M-1]
multiset<ll> U, L;
ll A[200010], answer;

int main(){
  int N, M, K; cin >> N >> M >> K;
  // define A[0] as sufficiently big number for simplification
  A[0] = 1e9 + 1;
  rep(i, 1, N+1) cin >> A[i];
  rep(i, 0, M) U.insert(A[i]);
  rep(i, 0, K){
    answer += *U.begin();
    L.insert(*U.begin());
    U.erase(U.begin());
  }
  
  
  rep(i, M, N+1){
    // delete A[i-M]
    if(U.count(A[i-M]) > 0){
      U.erase(U.find(A[i-M]));
    }else{
      L.erase(L.find(A[i-M]));
      answer -= A[i-M];
    }

    U.insert(A[i]);

    // in the case A[i-M] is deleted from L
    if(L.size() < K){
      answer += *U.begin();
      L.insert(*U.begin());
      U.erase(U.begin());
    }else{
      auto it_back = L.end(); --it_back;
      ll maximum = *it_back, minimum = *U.begin();
      if(minimum < maximum){
        answer += minimum - maximum;
        L.insert(minimum);
        U.insert(maximum);
        L.erase(it_back);
        U.erase(U.begin());
      }
    }
    cout << answer << ' ';
  }
  cout << endl;
  return 0;
}