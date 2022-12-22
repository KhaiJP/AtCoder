#include<iostream>
using namespace std;

int main(){
  int N; cin >> N;
  int prev = 0; int currnet = 0;
  for(int i=0; i<N; ++i){
    cin  >> currnet;
    cout << currnet-prev << ' ';
    prev = currnet;
  }
  cout << endl;
  return 0;
}