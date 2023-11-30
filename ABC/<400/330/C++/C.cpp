#include<iostream>
#include<cmath>
using namespace std;
using ll = int64_t;

ll D, answer;

int main(){
  cin >> D;
  answer = 1e18;
  for(ll x = 0; x*x <= D+10; ++x){
    ll y = floor(sqrt(D-x*x));
    if(y >= 0){
      answer = min(answer, abs(x*x + y*y - D));
      answer = min(answer, abs(x*x + (y+1)*(y+1) - D));
    }
  }
  cout << answer << endl;
}