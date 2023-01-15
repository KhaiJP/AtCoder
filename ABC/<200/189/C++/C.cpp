#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef int64_t ll;
#define rep(i,s,t) for(int i = (s); i < (t); ++i)

const int pInf32 =  1000000000;
int main(){
  int N; cin >> N;
  vector<int> A(N+1); rep(i,1,N+1) cin >> A[i];
  int answer = 0;
  rep(l,1,N+1)rep(r, l, N+1){
    int minAlr = *min_element(A.begin()+l, A.begin()+r);
    cout << l << ' ' << r << ' ' << minAlr << '\n';
    cout << *(A.begin()+l) << ' ' << *(A.begin()+r) << ' ' << minAlr << '\n';
    answer = max( (r-l+1)*minAlr, answer);
  }
  cout << answer << endl;
}

// naive O(N^2) solution
int main(){
  int N; cin >> N;
  vector<int> A(N+1); rep(i,1,N+1) cin >> A[i];
  int answer = 0;
  rep(l,1,N+1){
    int tmp_ans = 0;
    int tmp_min = pInf32;
    rep(r, l, N+1){
      tmp_min = min(tmp_min, A[r]);
      tmp_ans = (r-l+1) * tmp_min;
      answer = max(answer, tmp_ans);
    }
  }
  cout << answer << endl;
  return 0;
}