#include<iostream>
#include<deque>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

deque<char> q[200010];
string S;
int col[200010];

int main(){
  int N, M; cin >> N >> M;
  cin >> S;
  rep(i, 0, N){
    cin >> col[i]; --col[i];
    q[col[i]].push_back(S[i]);
  }
  rep(i, 0, M){
    char c = q[i].back(); q[i].pop_back();
    q[i].push_front(c);
  }

  rep(i, 0, N){
    cout << q[col[i]].front();
    q[col[i]].pop_front();
  }
  cout << endl;
  return 0;
}