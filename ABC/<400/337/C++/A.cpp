#include<iostream>
using namespace std;

int N, Tak, Aok;

int main(){
  cin >> N;
  while(N--){
    int X, Y; cin >> X >> Y;
    Tak += X;
    Aok += Y;
  }

  if(Tak == Aok) cout << "Draw" << endl;
  if(Tak >  Aok) cout << "Takahashi" << endl;
  if(Tak <  Aok) cout << "Aoki" << endl;
  return 0;
}