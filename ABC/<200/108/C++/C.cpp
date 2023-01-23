#include<iostream>
using namespace std;
typedef int64_t ll;
/*
 (a+b)%K = (a+c)%K = 0 -> b%K = c%K ( = a%K).
 hence a%K = b%K = c%K = 0 or K/2(if K is even)
 if N has m integers whose residue are r(= 0 or K/2),
 then N has m^3 integer sets that satisfy the condition.
*/
int main(){
  ll N, K; cin >> N >> K;
  ll answer = 0, m;

  // number of integers i in [1,N] that i mod K = 0; 
  m = N/K; 
  answer += mod_0 *  mod_0 * mod_0;

  if( K%2 == 0){
    // N must have, at least, N/K integers whose residue is K/2.
    // if N%K >= K/2, then N has additional one integer.
    m = N/K + (N%K >= K/2 ? 1 : 0);
    answer += mod_0 *  mod_0 * mod_0;
  }
  cout << answer << endl;
  return 0;
}