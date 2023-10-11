#include<iostream>
using namespace std;

// aweful example
int main(){
  int deg, dis; cin >> deg >> dis;
  deg = 10*deg;
  double f = (double)1 * dis / 60;

  int d;
  if(f < 0.25)      d = 0;
  else if(f < 1.55)  d = 1;
  else if(f < 3.35)  d = 2;
  else if(f < 5.45)  d = 3;
  else if(f < 7.95)  d = 4;
  else if(f < 10.75) d = 5;
  else if(f < 13.85) d = 6;
  else if(f < 17.15) d = 7;
  else if(f < 20.75) d = 8;
  else if(f < 24.45) d = 9;
  else if(f < 28.45) d = 10;
  else if(f < 32.65) d = 11;
  else               d = 12;

  string c;
  if(d == 0)           c = "C";
  else if(deg < 1125)  c = "N";
  else if(deg < 3375)  c = "NNE";
  else if(deg < 5625)  c = "NE";
  else if(deg < 7875)  c = "ENE";
  else if(deg < 10125) c = "E";
  else if(deg < 12375) c = "ESE";
  else if(deg < 14625) c = "SE";
  else if(deg < 16875) c = "SSE";
  else if(deg < 19125) c = "S";
  else if(deg < 21375) c = "SSW";
  else if(deg < 23625) c = "SW";
  else if(deg < 25875) c = "WSW";
  else if(deg < 28125) c = "W";
  else if(deg < 30375) c = "WNW";
  else if(deg < 32625) c = "NW";
  else if(deg < 34875) c = "NNW";
  else                 c = "N";

  cout << c << ' ' << d << endl;
  return 0;
}