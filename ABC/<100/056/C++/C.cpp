#include<iostream>
using namespace std;

/*
 At t = 0, only position 0 can be realised. At t = 1, positions -1, 0, +1 can be realised.
 At t = 2, positions -3, -2, -1, 0, +1, +2, +3 can be realised.
 At t = k, every interger positions from -n*(n+1)/2 to n*(n+1)/2   
*/
int main(){
  int X; cin >> X;
  int i = 0;
  int limit = 0;
  while(limit<X){
    i += 1;
    limit += i;
  }
 cout << i <<endl;
 return 0;
}