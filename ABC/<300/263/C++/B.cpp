#include <iostream>
using namespace std;

int main(){
  int R, C; cin >> R >> C;
  bool clr = false;
  if(R==1 || R==15) clr = true;
  if(R==3 || R==13)if(C!=2 && C!=14) clr = true;
  if(R==5 || R==11)if(C!=2 && C!= 4 && C!= 12 && C!=14) clr = true;
  if(R==7 || R==9)if(C!=2 && C!= 4 && C!=6 && C!= 10 && C!= 12 && C!=14) clr = true;
  if(R==2 || R==14)if(C==1 || C==15) clr = true;
  if(R==4 || R==12)if(C==1 || C==3 || C==13 || C==15) clr = true;
  if(R==6 || R==10)if(C==1 || C==3 || C==5 || C==11 || C==13 || C==15) clr = true;
  if(R==8)if(C==1 || C==3 || C==5 || C==7 || C==9 || C==11 || C==13 || C==15) clr = true;
  cout << (clr ? "black" : "white") << endl;
  return 0;
}