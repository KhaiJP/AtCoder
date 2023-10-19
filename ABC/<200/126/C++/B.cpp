#include<iostream>
using namespace std;

bool canbe_month(string s){
  int a = stoi(s);
  return 0 < a && a < 13;
}

int main(){
  string former = "", latter = "";
  char c0, c1, c2, c3; cin >> c0 >> c1 >> c2 >> c3;
  former += c0; former += c1;
  latter += c2; latter += c3;
  if(canbe_month(former) && canbe_month(latter)){
    cout << "AMBIGUOUS" << endl;
  }
  if(canbe_month(former) && !canbe_month(latter)){
    cout << "MMYY" << endl;
  }
  if(!canbe_month(former) && canbe_month(latter)){
    cout << "YYMM" << endl;
  }
  if(!canbe_month(former) && !canbe_month(latter)){
    cout << "NA" << endl;
  }
  return 0;
}