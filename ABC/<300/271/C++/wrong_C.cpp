/*
 algorithm below has counterexample:
 8
 1 1 1 1 3 4 6
*/


#include<iostream>
#include<vector>
#include<algorithm>

#define rep(i,s,t) for(int i=(s); i<(t); ++i)
using namespace std;

int main(){
  int N; cin >> N;
  vector<int> A(N+1,0); rep(i,1,N+1) cin >> A[i];
  sort(A.begin(), A.end());
  int id = 1, volume= 0, sold = N;
  while(true){
    // cout << "id: " << id << ", A[id]: " << A[id] << ", sold: " << sold << ", volume: " << volume << '\n';
    if(id == N+1 || A[id]==0){
      cout << volume << endl;
      return 0;
    }
    if(A[id]==volume+1){
      // cout << "id: " << id << ", A[id]: " << A[id] << ", sold: " << sold << ", volume: " << volume << '\n';
      id += 1;
      volume += 1;
      int delta = 0;
      while(id+delta <= N && A[id+delta]==volume && sold > id + delta && A[sold] != 0){
        // cout << "id: " << id+delta << ", sold: " << sold << '\n';
        delta += 1;
        A[sold] = 0;
        sold -= 1;
      }
      id += delta;
      volume += delta;
      continue;
    }
    // cout << "id: " << id << " sold: " << sold << " volume: " << volume << '\n';
    if(sold-1 >= id && A[sold]!=0 && A[sold-1]!=0){
      A[sold] = 0, A[sold-1] = 0;
      sold -= 2;
      volume += 1;
      continue;
    }
    // rep(i,1,N+1) cout << A[i] << ' ';
    // cout << '\n';
    cout << volume << endl;
    return 0;
  }
}