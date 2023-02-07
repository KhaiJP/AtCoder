#include<iostream>
#include<string>
#include<set>
#include<map>
using namespace std;
#define rep(i,s,t) for(int i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)

map<char, int> mS[55];
set<char> keys;

int main(){
  int n; cin >> n;
  
  rep(i,0,n){
    string s; cin >> s;
    rep(j,0,s.size()){
      ++mS[i][s[j]];
      keys.insert(s[j]);
    }
  }

  multiset<char> ans;
  fore(key, keys){
    int num_key = 1000000000+7;
    rep(i,0,n){
      num_key = min(num_key, mS[i][key]);
    }
    rep(i,0,num_key) ans.insert(key);
  }
  
  fore(c, ans) cout << c; cout << endl;
  return 0;
}