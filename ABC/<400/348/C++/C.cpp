#include<iostream>
#include<map>
#include<set>
using namespace std;

int N, answer;
map<int, set<int>> m;

int main(){
  cin >> N;
  while(N--){
    int A, C; cin >> A >> C;
    m[C].insert(A);
  }

  for(auto p : m){
    answer = max(answer, *p.second.begin());
  }

  cout << answer << endl;
  return 0;
}