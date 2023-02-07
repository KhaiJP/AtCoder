#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define yes "Yes"
#define noo "No"

int C[4][4];

int main(){
  rep(i,1,4)rep(j,1,4) cin >> C[i][j];
  bool isa21Valid = ( C[2][1] - C[1][1] == C[2][2] - C[1][2] && C[2][1] - C[1][1] == C[2][3] - C[1][3]);
  bool isa31Valid = ( C[3][1] - C[1][1] == C[3][2] - C[1][2] && C[3][1] - C[1][1] == C[3][3] - C[1][3]);
  bool isa32Valid = ( C[3][1] - C[2][1] == C[3][2] - C[2][2] && C[3][1] - C[2][1] == C[3][3] - C[2][3]);

  bool isb21Valid = ( C[1][2] - C[1][1] == C[2][2] - C[2][1] && C[1][2] - C[1][1] == C[3][2] - C[3][1]);
  bool isb31Valid = ( C[1][3] - C[1][1] == C[2][3] - C[2][1] && C[1][3] - C[1][1] == C[3][3] - C[3][1]);
  bool isb32Valid = ( C[1][3] - C[1][2] == C[2][3] - C[2][2] && C[1][3] - C[1][2] == C[3][3] - C[3][2]);

  if(isa21Valid && isa31Valid && isa32Valid  &&  isb21Valid && isb31Valid && isb32Valid){
    cout << yes << endl;
  }else{
    cout << noo << endl;
  }
  return 0;
}