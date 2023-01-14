#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int min_greater(vector<int> &v, int a);

int main(){
  int N, Q; cin >> N >> Q;
  vector<int> A(N); rep(i,0,N) cin >> A[i];
  sort(A.begin(), A.end());

  rep(q,0,Q){
    int x; cin >> x;
    cout << N - min_greater(A, x) << '\n';
  }
  cout << endl;
  return 0;
}

int min_greater(vector<int> &v, int a){
  int L =  v.size();
  if(v[0] > a) return 0;
  if(v[L-1] < a) return L;
  int ng = -1, ok = L;
  while(ok - ng > 1){
    int mid = (ok+ng)/2;
    if(v[mid] >= a) ok = mid;
    else           ng = mid;
  }
  return ok;
}