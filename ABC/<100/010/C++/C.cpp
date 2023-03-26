#include<iostream>
#include<cmath>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define yes "YES"
#define noo "NO"

int main(){
  double xa, ya, xb, yb, T, V; cin >> xa >> ya >> xb >> yb >> T >> V;
  int n; cin >> n;
  bool flag = false;

  rep(i, 0, n){
    double x, y; cin >> x >> y;
    double d1 = sqrt( (xa - x)*(xa - x) + (ya - y) * (ya - y) );
    double d2 = sqrt( (xb - x)*(xb - x) + (yb - y) * (yb - y) );
    
    if(d1 + d2 <= V*T + 0.0000000001){
      flag = true;
      break;
    }
  }

  cout << (flag ? yes : noo) << endl;
  return 0;
}