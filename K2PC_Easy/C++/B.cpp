#include<iostream>
#include<string>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define yes "YES"
#define noo "NO"

multiset<int> limit, ref;
int max_len[7], pre[7];

int main(){
  int N; cin >> N;
  rep(i,0,10){
    int l; cin >> l;
    limit.insert(-l);
  }
  rep(n, 0, N){
    string C; cin >> C;
    rep(i, 0, 7){
      if(C[i] == 'X'){
        ++pre[i];
        max_len[i] = max(max_len[i], pre[i]);
      }
      if(C[i] == '-') pre[i] = 0;
    }
  }
  rep(i, 0, 7) ref.insert(-max_len[i]);
  
  
  auto itr_l = limit.begin(), itr_r = ref.begin();
  rep(i, 0, 7){
    if(*itr_l > *itr_r){cout << noo << endl; return 0;}
    ++itr_l, ++itr_r;
  }

  cout << yes << endl;
  return 0;
}