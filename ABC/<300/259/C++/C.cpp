#include<iostream>
#include<string>
using namespace std;

// greedy
int main(){
  string S, T; cin >> S >> T;
  int index_s = 0, index_t = 0;
  while(index_t<T.size()){
    if(index_s == S.size()){
      for(int i_t = index_t; i_t<T.size(); i_t++){
        if(T[i_t] != T[i_t-1]){
          cout << "No" << endl;
          return 0;
        }
      }
      cout << "Yes" << endl;
      return 0;
    }

    if(S[index_s] == T[index_t]){
      index_s++;
      index_t++;
      continue;
    }

    if(index_t < 2 || T[index_t-1] != T[index_t] || T[index_t-2]!=T[index_t]){
      cout << "No" << endl;
      return 0;
    }else index_t++;
  }  
  cout << "Yes" << endl;
  return 0;
}