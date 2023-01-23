#include<iostream>
#include<string>
using namespace std;
#define yes "Yes"
#define noo "No"

int main(){
  string N; cin >> N;
  cout << (N.front() == N.back() ? yes : noo ) << endl;
  return 0;
}