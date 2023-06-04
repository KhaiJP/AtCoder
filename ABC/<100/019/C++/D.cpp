#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N;
  
  int fartherst = 0;
  int a = 1, b;
  rep(i, 2, N+1){
    cout << "? " << a << ' ' << i << endl;
    int dist; cin >> dist;
    if(dist > fartherst){
      fartherst = dist;
      b = i;
    }
  }

  rep(i, 1, N+1){
    cout << "? " << b << ' ' << i << endl;
    int dist; cin >> dist;
    fartherst = max(fartherst, dist);
  }

  cout << "! " << fartherst << endl;
  return 0;
}