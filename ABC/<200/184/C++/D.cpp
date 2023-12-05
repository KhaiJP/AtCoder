#include<iostream>
#include<iomanip>
using namespace std;

double dp[110][110][110];

double E(int a, int b, int c){
  if(dp[a][b][c] > 0)                     return dp[a][b][c];
  if(a == 100  ||  b == 100  || c == 100) return 0;
  
  double result = 0;
  int denominator = a + b + c;
  if(a) result += (E(a+1, b  , c  ) + 1) * a / denominator;
  if(b) result += (E(a  , b+1, c  ) + 1) * b / denominator;
  if(c) result += (E(a  , b  , c+1) + 1) * c / denominator;
  dp[a][b][c] = result;
  return result;
}

int main(){
  int A, B, C; cin >> A >> B >> C;
  cout << fixed << setprecision(9) << E(A, B, C) << endl;
}