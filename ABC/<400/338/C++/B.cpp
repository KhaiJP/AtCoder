#include<iostream>
#include<map>
using namespace std;

map<char, int> cnt;
string S;
int max_cnt;

int main(){
  cin >> S;

  for(char c : S) ++cnt[c];
  for(auto p : cnt) max_cnt = max(max_cnt, p.second);
  for(auto p : cnt)if(p.second == max_cnt){
    cout << p.first << endl;
    return 0;
  }
}