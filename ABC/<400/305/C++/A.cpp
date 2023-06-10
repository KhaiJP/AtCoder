#include<iostream>
using namespace std;

int drop(int n, int mod){ return mod * (n / mod); }
int raise(int n, int mod){ return mod * ((n + mod - 1)/ mod);}

int main(){
  int N; cin >> N;
  cout << (N - drop(N, 5) < raise(N, 5) - N ? drop(N, 5) : raise(N, 5)) << endl;
  return 0;
}