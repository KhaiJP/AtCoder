#include<iostream>
#include<string>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)


const int pInf32 =  1000000000+7;
const int nInf32 = -1000000000-7;
const int64_t pInf64 =  1000000000000000000;
const int64_t nInf64 = -1000000000000000000;

int main(){
  string S; cin >> S;
  set<char> Alphabets; fore(c, S) Alphabets.insert(c);
  rep(i, 0, 26){
    char c = (char)(i+97);
    if(Alphabets.count(c) != 1){cout << c << endl; return 0;}
  }
  cout << "None" << endl; return 0;
}