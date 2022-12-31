#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

#define rep(i,s,t) for(int i=(s); i<(t); ++i)
using namespace std;

int main(){
  int N; cin >> N;
  vector<int> A;
  unordered_set<int> lg;
  int excess = 0;
  rep(i,0,N){
    int tmp; cin >> tmp;
    if(lg.count(tmp)==1) excess += 1;
    else{
      A.push_back(tmp);
      lg.insert(tmp);
    }
  }
  sort(A.begin(), A.end());
  int id = 0, volume = 0, limit = A.size();
  int sold = limit-1;
  while(true){
    if(id < limit && A[id] == volume+1) id += 1;
    else if(excess >= 2) excess -= 2;
    else if(excess == 1 && sold >= id && A[sold] != 0 ){
      A[sold] = 0;
      sold -= 1;
      excess -= 1;
    }else if(id < limit && sold-1 >= id && A[sold-1] != 0 && A[sold] != 0){
      A[sold] = 0, A[sold-1] = 0;
      sold -= 2;
    }else break;

    volume += 1;
  }
  cout << volume << endl;
  return 0;
}