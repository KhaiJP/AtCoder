#include<iostream>
#include<set>
using namespace std;

int main(){
  int N; cin >> N;
  set<int> s;
  for(int i = 0; i < N; ++i){
    int a; cin >> a;
    s.insert(a);
  }
  auto itr = s.rbegin(); --itr;
  cout << *itr << endl;
  return 0;
}