#include<iostream>
#include<vector>
#include<set>
#define rep(i, s, t) for (int i = (s); i < (t); ++i)
using namespace std;
const int pInf32 =  1000000000;

int main(){
  int N, K; cin >> N >> K;
  set<int> heads;                  // cards appear on the table.
  vector<int> preds(N+1, pInf32);  // preds[P]: the card just under P. if -1, P is on the table.
  vector<int> height(N+1, pInf32); // hegit[P]: the height of the pile of which the top is P. 
  vector<int> when_eaten(N+1, -1); // when_eaten[P]: the turn P is eaten.
  rep(i,0,N){
    // draw a card
    int P; cin >> P;
    auto itr = heads.upper_bound(P);
    if(itr == heads.end()){
      preds[P] = -1;
      height[P] = 1;
    }
    // when P is on no other cards
    else{
      preds[P] = (*itr);
      height[P] = height[(*itr)] + 1;
      heads.erase(itr);
    }
    //  put P on the table
    heads.insert(P);
    //  check if the stack of which the top is P has height K
    if(height[P] == K){
      int Q = P;
      while(Q!= -1){
        when_eaten[Q] = i+1;
        Q = preds[Q];
      }
      heads.erase(P);
    }
  }
  rep(i,1,N+1) cout << when_eaten[i] << '\n';
  cout << endl;
  return 0;
}