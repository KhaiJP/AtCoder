#include<iostream>
using namespace std;
using pp = pair<int, pair<int, int>>;

pp R{2019, {4, 30}}, P;
char t;

int main(){
  cin >> P.first >> t >> P.second.first >> t >> P.second.second;
  cout << (P <= R ? "Heisei" : "TBD") << endl;
  return 0;
}