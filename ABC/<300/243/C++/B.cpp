#include<iostream>
#include<unordered_set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int A[1010], B[1010];
unordered_set<int> histA;
int main(){
  int N; cin >> N;
  int ans1 = 0, ans2 = 0;
  
  rep(i,0,N){
    int a; cin >> a;
    A[i] = a;
    histA.insert(a);
  }
  rep(i,0,N){
    int b; cin >> b;
    B[i] = b;
    ans1 += B[i] == A[i];
    ans2 += B[i] != A[i] && histA.count(B[i]);
  }

  cout << ans1 << '\n' << ans2 << endl;
  return 0; 
}