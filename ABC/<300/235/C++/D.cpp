#include<iostream>
#include<string>
#include<vector>
#include<deque>
using namespace std;
typedef int64_t ll;
ll ston(string s);
string ntos(ll n);
void rotate(string &s);

int main(){
  ll a, N; cin >> a >> N;
  
  ll M = 1;
  while(M <= N) M *= 10;

  vector<ll> num_operations(M, -1);
  deque<ll> dq;
  num_operations[1] = 0;
  dq.push_back(1);

  while(!dq.empty()){
    ll n = dq.front(); dq.pop_front();
    ll &nos = num_operations[n];

    ll op1 = a*n;
    if(op1 < M && num_operations[op1] == -1){
      num_operations[op1] = nos+1;
      dq.push_back(op1);
    }

    if(n >= 10 && n%10 != 0){
      string s = ntos(n); rotate(s);
      ll op2 = ston(s);
      if(op2 < M && num_operations[op2] == -1){
        num_operations[op2] = nos+1;
        dq.push_back(op2);
      }
    }
  }
  cout << num_operations[N] << endl;
  return 0;
}

ll ston(string s){
  ll ret = 0;
  ll ten = 1;
  for(ll i = s.size()-1; i >= 0; --i){
    ret += ten*((ll)(s[i]-'0'));
    ten *= 10;
  }
  return ret;
}
string ntos(ll n){
  if(n == 0) return "0";
  string ret = "";
  while(n > 0){
    ret = (char)(n%10 + '0') + ret;
    n /= 10;
  }
  return ret;
}
void rotate(string &s){
  s = s[s.size()-1]+s;
  s.erase(s.size()-1);
}
