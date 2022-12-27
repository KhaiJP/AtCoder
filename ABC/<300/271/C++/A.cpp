#include<iostream>
using namespace std;
int main(){
  char num[] = "0123456789ABCDEF";
  int N; cin >> N;
  cout << num[N/16] << num[N%16] <<  endl;
  return 0;
}