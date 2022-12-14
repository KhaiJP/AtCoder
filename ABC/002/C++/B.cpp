#include<iostream>
#include<cstring>
using namespace std;
int main(){
  char W[30]; cin >> W;
  for(int i=0; i<strlen(W); ++i){
    if(W[i]!='a' && W[i]!='e' && W[i]!='i' && W[i]!='o' && W[i]!='u') cout <<  W[i];
  }
  cout << endl;
  return 0;
}