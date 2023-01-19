#include<iostream>
#include<string>
using namespace std;

int ston(string s);
string ntos(int n);
void rotate(string &s);

int main(){
  int abc; cin >> abc;
  string s = ntos(abc); rotate(s);
  int cab = ston(s); rotate(s);
  int bca = ston(s);
  cout << abc + bca + cab << endl;
  return 0;
}

int ston(string s){
  int ret = 0;
  int ten = 1;
  for(int i = s.size()-1; i >= 0; --i){
    ret += ten*((int)(s[i]-'0'));
    ten *= 10;
  }
  return ret;
}
string ntos(int n){
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