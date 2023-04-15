#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N;
  char pre = 'x';

  rep(i, 0, N){
    char sex; cin >> sex;
    if(sex == pre){
      cout << "No" << endl;
      return 0;
    }

    pre = sex;
  }

  cout << "Yes" << endl;
  return 0;
}
