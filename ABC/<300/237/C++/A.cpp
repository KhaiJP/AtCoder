#include<iostream>
using namespace std;

int main(){
  int64_t N; cin >> N;
  cout << (-((int64_t)1<<31) <= N && N < ((int64_t)1<<31) ? "Yes" : "No") << endl;
  return 0;
}