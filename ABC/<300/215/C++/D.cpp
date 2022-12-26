#include<iostream>
#include<vector>
#define rep(i,s,t) for(int i=(s); i<(t); ++i)
using namespace std;

int main(){
  int N, M; cin >> N >> M;
  if(M==1){
    cout << 1 << '\n' << 1 << endl;
    return 0;
  }
  vector<bool> S(M+1, true); 
  rep(i,0,N){
    int Ai; cin >> Ai;
    // prime factoring by Eratosthenes
    if(Ai%2==0){
      while(Ai%2==0) Ai /= 2;
      // crossing out the multiples of 2
      if(2<=M && S[2]) rep(n, 1, M/2+1) S[n*2] = false;
    }
    int p = 3;
    while(p*p<=Ai){
      if(Ai%p==0){
        while(Ai%p==0) Ai /= p;
        // crossing out the multiples of p
        if(p<=M && S[p]) rep(n, 1, M/p+1) S[n*p] = false;
      }
      p += 2;
    }
    // if Ai is not 1, then Ai must be a prime of Ai > M. if Ai < M, crossing out the multiples of Ai
    if(p<=M && Ai!=1) if(S[Ai]) rep(n, 1, M/Ai+1) S[n*Ai] = false;
  }

  vector<int> v;
  rep(i,1,M+1) if(S[i]) v.push_back(i);
  cout << v.size() << '\n';
  rep(i,0,v.size()) cout << v[i] << '\n';
  cout << endl;  
  return 0;
}