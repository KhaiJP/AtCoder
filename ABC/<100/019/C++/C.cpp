#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N;
  set<int> answer;

  rep(i, 0, N){
    int a; cin >> a;
    while(a%2 == 0) a /= 2;
    answer.insert(a);
  }

  cout << answer.size() << endl;
  return 0;
}