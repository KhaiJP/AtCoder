#include<iostream>
#include<map>
using namespace std;

int N, answer;
string S;
map<char, int> m;

int main(){
  cin >> N >> S;
  S += 'Z';

  char pre = 'X';
  int l = 0;
  for(auto c : S){
    if(c == pre) ++l;
    else{
      m[pre] = max(m[pre], l);
      pre = c;
      l = 1;
    }
  }

  for(auto p : m) answer += p.second;

  cout << answer << endl;
  return 0;
}