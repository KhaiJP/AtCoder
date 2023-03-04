#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define yes "Yes"
#define noo "No"

int card[110];

int main(){
  int N, Q; cin >> N >> Q;
  rep(i, 0, Q){
    int e, x; cin >> e >> x;
    if(e == 1) card[x] += 1;
    if(e == 2) card[x] += 2;
    if(e == 3) cout << (card[x] > 1 ? yes : noo) << '\n';
  }

  cout << endl;
  return 0;
}