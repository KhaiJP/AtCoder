#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// Let the yokan of length L be devided into L0, L1, ... , LK, where sum_k Lk = L.
// The score is P -> for any k, Lk >= P.
// A decision problem "Can the yokan the be divided into pieces with minimum length P?"
// can be solved by greedy algo in O(N) time.
// Binary search can be operated in O(logL) time -> this problem can be solved O(NlogL);

int A[100010], N, L, K;

bool areAllLongerThan(int l){
  int num_blocks = 0, ref_length = 0;

  rep(i, 1, N+2){
    ref_length += A[i]-A[i-1];

    if(ref_length >= l){
      ++num_blocks;
      ref_length = 0;
    }
  }

  return num_blocks >= K+1;
}

int solveByBinarySearch(){
  int left = -1, right = L+1;

  while(right > left + 1){
    int mid = (left + right) / 2;

    if( areAllLongerThan(mid) ) left = mid;
    else right = mid;
  }

  return left;
}

int main(){
  cin >> N >> L >> K;
  
  rep(i, 1, N+1) cin >> A[i];
  A[N+1] = L;

  cout << solveByBinarySearch() << endl;
  return 0;
}