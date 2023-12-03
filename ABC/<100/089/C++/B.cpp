#include<iostream>
#include<set>
using namespace std;

int main(){
  int N; cin >> N;
  set<char> S;
  for(int i = 0; i < N; ++i){
    char c; cin >> c;
    S.insert(c);
  }

  cout << ((int)S.size() == 3 ? "Three" : "Four") << endl;
  return 0;
}