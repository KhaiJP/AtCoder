#include<iostream>
#include<iomanip>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

multiset<int> X;

int main(){
  int N; cin >> N;
  rep(i,0,5*N){
    int x; cin >> x;
    X.insert(-x);
  }
  
  auto itr = X.begin();
  rep(i, 0, N) itr++;
  double answer = 0;
  rep(i, 0, 3*N){
    answer -= *itr;
    itr++;
  }
  answer /= 3*N;

  cout << fixed << setprecision(10) << answer << endl;
  return 0;
}