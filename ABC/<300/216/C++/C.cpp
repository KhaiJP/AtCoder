#include<iostream>
#include<stack>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

int main(){
  ll N; cin >> N;

  stack<char> st;
  while(N){
   if(N&1){
    st.push('A');
    --N;
   }else{
    st.push('B');
    N /= 2;
   }
  }

  while(!st.empty()){
    cout << st.top();
    st.pop();
  }

  cout << endl;
  return 0;
}