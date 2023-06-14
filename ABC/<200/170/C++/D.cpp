#include<iostream>
#include<unordered_map>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int A[200010];

int main(){
  int N; cin >> N;
  
  int M = 0;
  unordered_map<int, int> m;
  rep(i, 0, N){
    cin >> A[i];
    M = max(M, A[i]);
    ++m[A[i]];
  }

  rep(i, 0, N){
    int &key = A[i];
    if(m.count(key) == 0) continue;
    
    for(int j = 2; j*key <= M; ++j){
      if(m.count(j*key) == 1) m.erase(j*key);
    }
    if(m[key] > 1) m.erase(key);
  }

  cout << m.size() << endl;
  return 0;
}