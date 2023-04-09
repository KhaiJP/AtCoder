#include<iostream>
using namespace std;

int N;

// s = "aaa" -> 1, s = "aab" -> 2, "aba" -> 2, "abc" -> 3, 
int get_char_kinds_in(string &s){
  bool used[10]; for(int i = 0; i < 10; ++i) used[i] = false;
  for(char c : s) used[c - 'a'] = true;
  
  int kinds = 0;
  for(int i = 0; i < 10; ++i) kinds += used[i];

  return kinds;
}

void dfs(string s = ""){
  if( (int)s.size() == N ) cout << s << '\n';
  else{
    int kinds = get_char_kinds_in(s);

    // if s consists of a, b and c, e or greater cannot appear in the next branch
    for(char c = 0; c < kinds + 1; ++c){
      string next = s + (char)('a' + c);
      dfs( next );
    }
  }
}

int main(){
  cin >> N;
  dfs();
  cout << endl;
  return 0;
}