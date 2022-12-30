#include<iostream>
#include<vector>

#define rep(i,s,t) for(int64_t i=(s); i<(t); ++i)
using namespace std;

int power_of_2(int64_t N);
void binary_N(int64_t N, int n, vector<int64_t> &v);

int main(){
  int64_t N; cin >> N;
  // 2^(N_len-1) <= N < 2^N_len 
  int N_len = power_of_2(N); 
  // ones[j] = (N/2^j)%2
  vector<int64_t> ones(N_len, 0);
  binary_N(N, N_len, ones); 
  // num_ones = sum(ones); there are 2^num_ones numbers that satisfy the condition
  int num_ones = 0; rep(i,0,N_len) num_ones += ones[i];
  
  rep(i,0,(1<<num_ones)){
    vector<int64_t> tmp_ones(num_ones, 0);
    binary_N(i, num_ones, tmp_ones);
    int64_t ans = 0;
    int tmp_i = 0;
    rep(j, 0, N_len){
      if(ones[j]){
        ans += (tmp_ones[tmp_i] << j);
        tmp_i += 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}

int power_of_2(int64_t N){
  int result = 1;
  while(N > 1){
    result += 1;
    N /= 2;
  }
  return result;
}
void binary_N(int64_t N, int n, vector<int64_t> &v){
  rep(i,0,n){
    v[i] = N%2;
    N /= 2;
  }
}