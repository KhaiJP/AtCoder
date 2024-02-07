#include<iostream>
#include<iomanip>
using namespace std;

int N, rate=380000;
double answer;

int main(){
  cin >> N;
  while(N--){
    double x; cin >> x;
    string u; cin >> u;
    if(u == "BTC") x *= rate;
    answer += x;
  }

  cout << fixed << setprecision(9) << answer << endl;
  return 0;
}