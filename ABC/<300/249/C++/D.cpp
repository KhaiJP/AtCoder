#include<iostream>
#include<vector>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)

int A[200000], CNT[200001];
const ll ll1 = 1;
void getDivisors(int n, vector<int> &divisors);

int main(){
  int N; cin >> N;
  rep(i,0,N){ cin >> A[i]; ++CNT[A[i]];}

  ll answer = 0;
  rep(i,0,N){
    vector<int> divs;
    getDivisors(A[i], divs);
    fore(Aj, divs){
      answer += ll1 * CNT[Aj]*CNT[A[i]/Aj]; 
    }
  }
  cout << answer << endl;
  return 0;
}

void getDivisors(int n, vector<int> &divisors){
  for(int i = 1; i*i <= n; ++i){
    if(n%i == 0){
      divisors.push_back(i);
      if(i*i == n) break;
      divisors.push_back(n/i);
    }
  }
}