#include<iostream>
using namespace std;

int A, B, C;
bool appeared[110];

int main(){
  cin >> A >> B >> C;
  
  for(int i = 1; ; ++i){
    int N = i * A;
    if(N % B == C){
      cout << "YES" << endl;
      return 0;
    }
    if(appeared[N%B]){
      cout << "NO" << endl;
      return 0;
    }
    appeared[N%B] = true;
  }
}