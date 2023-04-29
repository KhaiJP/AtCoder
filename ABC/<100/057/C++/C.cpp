#include<iostream>
#include<vector>
using namespace std;
using ll = int64_t;

ll N;
vector<pair<ll, ll>> P;

void divPair(){
  for(ll i = 1; i*i <= N; ++i)if(N % i == 0) P.push_back({i, N/i});
}

ll F(ll A, ll B){
  ll ordA = 0, ordB = 0;
  while(A){
    ++ordA;
    A /= 10;
  }
  while(B){
    ++ordB;
    B /= 10;
  }
  
  return max(ordA, ordB);
}

int main(){
  cin >> N;
  divPair();
  ll answer = F(P.back().first, P.back().second);
  cout << answer << endl;
  return 0;
}