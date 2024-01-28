#include<iostream>
#include<stack>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, start_point[400010];
stack<int> S;

int main(){
  cin >> N;
  // not to make S empty
  S.push(-1);

  rep(i, 0, N){
    int A, B; cin >> A >> B;
    if(A > B) swap(A, B);
    start_point[B] = A;
  }

  rep(i, 1, 2*N+1){
    if(start_point[i] == 0) S.push(i);
    else{
      if(S.top() != start_point[i]){
        cout << "Yes" << endl;
        return 0;
      }

      S.pop();
    }
  }

  cout << "No" << endl;
  return 0;
}