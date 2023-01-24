#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

set<int> getDivisors(int n);
int main(){
  int N, M; cin >> N >> M;
  // let the answer be denoted by G and M be denoted by G*ref
  // here ref = (a/G)_1:N >= N ( A_s:t = \sum_{k=s}^t A_k ).
  // the problem is to mind the minimum divisor of M that satisfies ref >= N
  set<int> divisors = getDivisors(M);
  int ref = *lower_bound(divisors.begin(), divisors.end(), N);
  cout << M/ref << endl;
  return 0;
}

set<int> getDivisors(int n){
  set<int> divisors;
  for(int i = 1; i*i <= n; ++i){
    if(n%i == 0){
      divisors.insert(i);
      if(i*i == n) break;
      divisors.insert(n/i);
    }
  }
  return divisors;
}