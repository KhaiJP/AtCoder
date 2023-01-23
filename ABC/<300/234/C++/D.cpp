#include<iostream>
#include<queue>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, K;

int main(){
  cin >> N >> K;
  priority_queue<int> pq;
  rep(i,0,K){
    int P; cin >> P;
    pq.push(-P);
  }
  cout << -pq.top() << '\n';
  rep(i, K, N){
    int P; cin >> P;
    if( P > -pq.top() ){
      pq.pop();
      pq.push(-P);
    }
    cout << -pq.top() << '\n';
  }
  cout << endl;
  return 0;
}