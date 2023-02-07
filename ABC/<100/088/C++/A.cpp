#include<iostream>
using namespace std;
#define yes "Yes"
#define noo "No"

int main(){
  int N, A; cin >> N >> A;
  cout << (N%500 <= A ? yes : noo) << endl;
  return 0;
}