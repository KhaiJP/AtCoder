#include<iostream>
using namespace std;

bool bought[110];

int main(){
  int a, b, c; cin >> a >> b >> c;
  bought[a] = bought[b] = bought[c] = true;
  int answer = 0;
  for(int i=1; i<=100; ++i) answer += bought[i];
  cout << answer << endl;
  return 0;
}
