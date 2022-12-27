#include<iostream>
#define rep(i,s,t) for(int64_t i=(s); i<(t); ++i)
using namespace std;
/* 
  Suppose N is positive and we have a sequence l:r with sum(l:r) = N,
  where l and r are positive integers(l <= r), and l:r = {l, l+1, ..., r-1, r}.
  Then apparently a sequence -(l-1):r also enjoys the condition; sum(-(l-1):r)
  as sum(-(l-1):r) = sum(l:r) + sum(-(l-1):(l-1)), and the second term is apparently 0.
  Hence if N is positive and there is a positive number sequence l:r with sum(l:r)=N, 
  there uniquely exists a sequence, with positive and non-positive number, associated with l:r.
  Even if N is negative, almost the same discussion above holds.
  Now, the probelm is to find such l:r.
  The shortest case is apparently when l=r=N, a sequence with a single number N.
  The potentially longest case is when l = 1. In this case, the sequence consists of O(sqrt(N)) numbers,
  hence no greater than 2*10^6.
  Let the length of a sequence l:r be L, hence r = l+L-1, then sum(l:r) = L*(2l+L-1)/2.
  If this equals N then we have 2 sequences. This can be confirmed by (2N-L^2+L)%2 == 0 then l = (2N-L^2+L)/2. 
*/
int main(){
  int64_t N; cin >> N;
  N = abs(N);
  int answer = 0;
  rep(L,1,2*1e6){
    if(L*L+L > 2*N) break; // even l = 1 case, L*(2l+L-2)/2 must be less than or equal to N
    if((2*N-L*L+L)%(2*L) == 0) answer += 2;
  }
  cout << answer << endl;
  return 0;
}