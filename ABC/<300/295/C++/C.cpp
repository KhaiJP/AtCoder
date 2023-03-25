#include<iostream>
#include<map>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N;
  map<int, int> m;

  int answer = 0;
  rep(i, 0, N){
    int a; cin >> a;
    ++m[a];
    if(m[a]%2 == 0) ++answer;
  }

  cout << answer << endl;
  return 0;
}