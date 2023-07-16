#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int H[100010];

int main(){
  int N; cin >> N;
  rep(i, 0, N) cin >> H[i];
  rep(i, 1, N)if(H[i-1] > H[i]) ++H[i];
  rep(i, 1, N)if(H[i-1] > H[i]){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}