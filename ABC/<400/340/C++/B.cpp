#include<iostream>
#include<vector>
using namespace std;

int main(){
  int Q; cin >> Q;
  vector<int> V;

  while(Q--){
    int e; cin >> e;
    
    if(e == 1){
      int x; cin >> x;
      V.push_back(x);
    }
    if(e == 2){
      int k; cin >> k;
      int n = V.size();
      cout << V[n-k] << endl;
    }
  }

  return 0;
}