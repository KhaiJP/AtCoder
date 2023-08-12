#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, Q, when[500010];
string S;

int main(){
  cin >> N >> S >> Q;

  int get_upper = -1, get_lower = -1;
  rep(j, 0, Q){
    int t, x; cin >> t >> x; --x;
    char c; cin >> c;
    
    if(t == 1){
      S[x] = c;
      when[x] = j;
    }
    if(t == 2){
      get_lower = j;
    }
    if(t == 3){
      get_upper = j;
    }
  }

  rep(i, 0, N){
    if(get_lower < get_upper && when[i] < get_upper)      cout << (char)toupper(S[i]);
    else if(get_upper < get_lower && when[i] < get_lower) cout << (char)tolower(S[i]);
    else                                                  cout << S[i];
  } cout << endl;
  
  return 0;
}