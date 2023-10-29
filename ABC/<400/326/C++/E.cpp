#include<iostream>
#include<atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, A[300010];
mint answer, p = 1, invN = 1, q = 1;

int main(){
  cin >> N;
  rep(i, 1, N+1) cin >> A[i];
  invN /= N;
  q += invN;
  rep(i, 1, N+1){
    answer += invN * p * A[i];
    p *= q;
  }
  cout << answer.val() << endl;
}