#include<iostream>
#include<set>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define yes "Yes"
#define noo "No"

int main(){
  set<string> ref = {"and", "not", "that", "the", "you"};

  int N; cin >> N;
  rep(i, 0, N){
    string W; cin >> W;
    if(ref.count(W) == 1){
      cout << yes << endl;
      return 0;
    }
  }  

  cout << noo << endl;
  return 0;
}